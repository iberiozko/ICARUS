#pragma once
#ifndef SUPERVISOR_H
#define SUPERVISOR_H
#include "CONFIG.h"
#include <thread>
#include "Config/configuration.h"
#include "Housekeeper/housekeeperworker.h"
namespace ICARUS {

class Supervisor {
public:
    Supervisor(Config::Configuration &config) : config(config) {};
    void start();

private:
    Config::Configuration &config;
    std::thread workingThread;

    bool running = true;
    void supervise();
};

} // namespace ICARUS
#endif // SUPERVISOR_H
