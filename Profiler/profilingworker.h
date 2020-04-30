#pragma once
#ifndef PROFILINGWORKER_H
#define PROFILINGWORKER_H
#include "../CONFIG.h"
#include "cppzmq/zmq.hpp"
#include "../Config/configuration.h"
#include "../worker.h"
namespace ICARUS {

class ProfilingWorker : public Worker {
public:
    ProfilingWorker(Config::Configuration &globalConfig, Config::Profiling &config) : Worker(globalConfig, config.workerCfg), config(config) {}

protected:
    bool Initialize() override;
    bool Finalize() override;
    bool Process() override;

private:
    Config::Profiling &config;

    zmq::context_t zmqContext{PROFILING_ZMQ_THREADS, PROFILING_ZMQ_MAX_SOCKETS};
    zmq::socket_t *zmqListener;
};

} // namespace ICARUS
#endif // PROFILINGWORKER_H
