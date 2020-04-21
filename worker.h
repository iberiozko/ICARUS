#pragma once
#ifndef WORKER_H
#define WORKER_H
#include "CONFIG.h"
#include <thread>
#include "Config/configuration.h"
namespace ICARUS {

enum WORKER_STATE { INIT, RUN, FIN, PANIC };

class Worker {
public:
    Worker(Config::Configuration &globalConfig) : globalConfig(globalConfig) {}
    void Run();
    void Tick();

protected:
    bool Initialize() { return false; }
    bool Finalize() { return false; }
    bool Process() { return false; }

    Config::Configuration &globalConfig;
    Config::WorkerCfg workerCfg = { 10.0, 5, 5, 5, false, "debug" }; // TODO
//    C &config;
    unsigned long long cycle;
    double now = 0.0;

    double getCurrentNow();

private:
    bool running = false;
    WORKER_STATE state =  INIT;
    std::thread workingThread;
    double sleeptime;
    unsigned long epoch = 0;

};

} // namespace ICARUS
#endif // WORKER_H
