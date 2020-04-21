#include "CONFIG.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "loguru/loguru.hpp"

#include "options.h"
#include "Config/configuration.h"
#include "supervisor.h"

// TEMP
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Первоначальная настройка
    Options options(argc, argv);
    loguru::init(argc, argv);
    LOG_F(WARNING, "ICARUS Aoolication starting...");

    // Грузим конфигурацию
    ICARUS::Config::Configuration config(options.configFilename);

    // Переключаем логгирование на боевое
    config.loggingOptions.configureLogging();
    LOG_F(WARNING, "Logging switched to production mode...");

    // Взводим супервизор, который будет запускать рабочие потоки
    ICARUS::Supervisor supervisor(config);
    supervisor.start();


    // TEMP
    while (true) { sleep(10); LOG_F(INFO, "main tick"); }
#ifdef FALSE
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
#endif
}
