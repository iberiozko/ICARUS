#include "../CONFIG.h"
#include <sys/time.h>
#include "loguru/loguru.hpp"
#include <QWindow>
#include <QScreen>
#include "guiworker.h"
namespace ICARUS {

bool GUIWorker::Initialize() {
    // Заводим экраны
    LOG_F(INFO, "Configuring screens...");
    for (auto it = config.screens.begin(); it != config.screens.end(); ++it) {
        if (!it->enabled) { continue; } // Игнорируем попросту те, что не включены
        // Если у нас полноэкранный режим, то надо убедиться, что такой экран есть
        if (it->fullScreen && it->screenId > app->screens().count() - 1) {
            LOG_F(WARNING, "Requested to allocate to screen %d, but it does not exist, ignoring!", it->screenId);
            continue;
        }

        // Грузим загрузочную QML-ку
        const QUrl bootstrapUrl(QString(it->bootstrap.c_str()), QUrl::ParsingMode::TolerantMode);
        // Убейте меня, но я не понимаю что тут происхоит...
        QObject::connect(
            engine, &QQmlApplicationEngine::objectCreated, app,
            [bootstrapUrl] (QObject *obj, const QUrl &objUrl) { if (!obj && bootstrapUrl == objUrl) QCoreApplication::exit(-1); },
            Qt::QueuedConnection
        );
        // Собственно грузим
        engine->load(bootstrapUrl);
        // У нас получается по идее окно в хвосте списка. Проставляем ему геометрию.
        QWindow *window = qobject_cast<QWindow *>(engine->rootObjects().last());
        QScreen *screen = app->screens().at(it->screenId);
        window->setScreen(screen);
        if (it->fullScreen) {
            LOG_F(INFO, "Configuring fullscreen window");
            window->setScreen(screen); window->showFullScreen();
        }
        else {
            LOG_F(INFO, "Setting window geometry to: [%d x %d] at (%d, %d)", it->width, it->height, it->x, it->y);
            window->setGeometry(it->x, it->y, it->width, it->height);
        }
        LOG_F(INFO, "  Allocated on screen: %s (%s, %s), geometry [%d x %d] at (%d, %d)",
              screen->name().toStdString().c_str(), screen->model().toStdString().c_str(), screen->manufacturer().toStdString().c_str(),
              screen->geometry().width(), screen->geometry().height(), screen->geometry().x(), screen->geometry().y()
              );

    }

    return true;
}
bool GUIWorker::Finalize() { return true; }

void GUIWorker::Process() {
//    LOG_F(INFO, "HELO FROM GUI TIMER THREAD!");
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

    // Регистрируем конфиг
    qmlConfig = globalConfig.toVariant(); rootContext->setContextProperty("config", qmlConfig);

    // Регистрируем логгер
    qmlLogger = new GUI::Logger(); rootContext->setContextProperty("logger", qmlLogger);

    // Запускаем таймер рабочего потока
    workingTimer = new QTimer(this);
    connect(workingTimer, SIGNAL(timeout()), this, SLOT(Process()));
    workingTimer->setInterval((int) (1000.0 / workerCfg.hz));
    workingTimer->start();

    // Инициализируем всю прочую обвязку
    if (! Initialize()) {
        ABORT_F("Failed to initialize GUI application module!");
        return;
    }

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
