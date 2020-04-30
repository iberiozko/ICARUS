#pragma once
#ifndef SUPERVISOR_H
#define SUPERVISOR_H
#include "CONFIG.h"
#include <thread>
#include <atomic>
#include "Config/configuration.h"
#include "Profiler/profiler.h"
#include "Profiler/profilingworker.h"
#include "Housekeeper/housekeeperworker.h"
#include "Heartbeat/heartbeatworker.h"
namespace ICARUS {

class Supervisor {
public:
    Supervisor(Config::Configuration &config) : config(config) { prof.setName("supervisor"); };
    void start();

private:
    Config::Configuration &config;
    std::thread workingThread;
    std::atomic_flag running;
    Profiler::Profiler prof;
    void supervise();
};

} // namespace ICARUS
#endif // SUPERVISOR_H
