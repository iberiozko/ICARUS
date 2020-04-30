#pragma once
#ifndef HEARTBEATWORKER_H
#define HEARTBEATWORKER_H
#include "../CONFIG.h"
#include "../Config/configuration.h"
#include "../worker.h"
namespace ICARUS {

class HeartbeatWorker : public Worker {
public:
    HeartbeatWorker(Config::Configuration &globalConfig, Config::Heartbeat &config) : Worker(globalConfig, config.workerCfg), config(config) {}

protected:
    bool Initialize() override;
    bool Finalize() override;
    bool Process() override;

private:
    Config::Heartbeat &config;
};

} // namespace ICARUS
#endif // HEARTBEATWORKER_H
