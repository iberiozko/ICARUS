#include "CONFIG.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <unistd.h>
#include "loguru/loguru.hpp"
#include "options.h"
#include "Config/configuration.h"
#include "supervisor.h"
#include "GUI/guiworker.h"


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

    // Запускаем графику, если она нужна
    if (config.gui.enabled) {
        ICARUS::GUIWorker guiWorker(config, config.gui);
        guiWorker.Run(argc, argv);
    }
    else {
        LOG_F(INFO, "GUI is not enabled, entering idle loop...");
        loguru::set_thread_name("console");
        while (true) { sleep(1); } // TODO Смотреть на супервизор, что ли?
    }

    LOG_F(INFO, "Application is terminating, finalizing...");
    // TODO
}
