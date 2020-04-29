#pragma once
#ifndef WORKER_H
#define WORKER_H
#include "CONFIG.h"
#include <thread>
#include <atomic>
#include "Config/configuration.h"
#include "Profiler/profiler.h"
namespace ICARUS {

enum WORKER_STATE { INIT, RUN, FIN, PANIC };

class Worker {
public:
    Worker(Config::Configuration &globalConfig, Config::WorkerCfg &workerCfg) : globalConfig(globalConfig), workerCfg(workerCfg) {
        // Какая там полезная инициализация у нас бывает...
        if (workerCfg.hz > 0.0) { sleeptime = 1.0 / workerCfg.hz; } else { sleeptime = 0.0; }
        prof.setName(workerCfg.name);
    };
    void Run();
    void Tick();

protected:
    virtual bool Initialize() { return false; }
    virtual bool Finalize() { return false; }
    virtual bool Process() { return false; }

    Config::Configuration &globalConfig;
    Config::WorkerCfg &workerCfg;
    Profiler::Profiler prof;
    unsigned long long cycle;
    double now = 0.0;

    double getCurrentNow();

private:
    std::atomic_flag running;
    WORKER_STATE state =  INIT;
    std::thread workingThread;
    double sleeptime;
    unsigned long epoch = 0;

};

} // namespace ICARUS
#endif // WORKER_H
