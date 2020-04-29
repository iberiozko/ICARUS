#include "../CONFIG.h"
#include <sys/time.h>
#include "loguru/loguru.hpp"
#include "guiworker.h"
namespace ICARUS {

bool GUIWorker::Initialize() { return true; }
bool GUIWorker::Finalize() { return true; }

void GUIWorker::Process() {
    LOG_F(INFO, "HELO FROM GUI TIMER THREAD!");
}

void GUIWorker::Run(int argc, char *argv[]) {
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard")); // Подключаем виртуальную клавиатуру таким вот образом
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling); // Что-то там про разрешение экрана

    // Инициализируем приложение
    LOG_F(INFO, "Initializing GUI...");
    loguru::set_thread_name(workerCfg.name.c_str());
    app = new QGuiApplication(argc, argv);
    engine = new QQmlApplicationEngine(this);
    rootContext = engine->rootContext();

    // Регистрируем логгер
    qmlLogger = new GUI::Logger(); rootContext->setContextProperty("logger", qmlLogger);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        engine,
        &QQmlApplicationEngine::objectCreated,
        app,
        [url] (QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl) QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection
    );
    engine->load(url);

    // Инициализируем всю прочую обвязку
    if (! Initialize()) {
        ABORT_F("Failed to initialize GUI application module!");
        return;
    }

    // Запускаем таймер рабочего потока
    workingTimer = new QTimer(this);
    connect(workingTimer, SIGNAL(timeout()), this, SLOT(Process()));
    workingTimer->setInterval((int) (1000.0 / workerCfg.hz));
    workingTimer->start();

    // Запускаем морду
    LOG_F(INFO, "Starting GUI application module...");
    int result = app->exec();
    LOG_F(INFO, "GUI application terminated with rc = %d", result);

    // Стопаем таймер рабочего потока
    workingTimer->stop();

    // Финализируемся
    if (! Finalize()) {
        ABORT_F("Failed to initialize GUI application module!");
        return;
    }
}

// Это хитрая получалочка текущего таймстемпа (вовсе не времени)
double GUIWorker::getCurrentNow() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    if (0 == epoch) { epoch = tv.tv_sec; }
    return (double)(tv.tv_sec - epoch) + (double)tv.tv_usec / 1000000.0;
}

} // namespace ICARUS
