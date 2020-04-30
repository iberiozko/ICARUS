#pragma once
#ifndef GUIWORKER_H
#define GUIWORKER_H
#include "../CONFIG.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QObject>
#include <QTimer>
#include "../Config/configuration.h"
#include "logger.h"
#include "../worker.h"
namespace ICARUS {

class GUIWorker : public QObject {
    Q_OBJECT

public:
    GUIWorker(Config::Configuration &globalConfig, Config::GUI &config) : globalConfig(globalConfig), workerCfg(config.workerCfg), config(config) {
        // Какая там полезная инициализация у нас бывает...
        if (workerCfg.hz > 0.0) { sleeptime = 1.0 / workerCfg.hz; } else { sleeptime = 0.0; }
        prof.setName(workerCfg.name);
    }
    void Run(int argc, char *argv[]);

protected slots:
    void Process();

protected:
    bool Initialize();
    bool Finalize();
    double getCurrentNow();

private:
    Config::Configuration &globalConfig;
    Config::WorkerCfg &workerCfg;
    Config::GUI &config;
    Profiler::Profiler prof;
    unsigned long long cycle;
    double now = 0.0;
    unsigned long epoch = 0;
    double sleeptime;

    QGuiApplication *app;
    QQmlApplicationEngine *engine;
    QQmlContext *rootContext;
    GUI::Logger *qmlLogger;
    QVariant qmlConfig;
    QTimer *workingTimer;
};

} // namespace ICARUS
#endif // GUIWORKER_H
