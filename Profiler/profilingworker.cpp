#include "../CONFIG.h"
#include "loguru/loguru.hpp"
#include "profilingworker.h"
namespace ICARUS {

bool ProfilingWorker::Initialize() {
    zmqListener = new zmq::socket_t(zmqContext, zmq::socket_type::sub);
    try {
        zmqListener->bind(PROFILING_ZMQ_SOCKET);
        zmqListener->set(zmq::sockopt::subscribe, "");
    }
    catch (const std::exception &e) {
        LOG_F(ERROR, "Failed to initialize messaging socket: %s: %s", PROFILING_ZMQ_SOCKET.c_str(), e.what());
        return false;
    }
    return true;
}

bool ProfilingWorker::Finalize() {
    try { zmqListener->close(); }
    catch (const std::exception &e) { LOG_F(ERROR, "Failed to close messaging socket: %s", e.what()); return false; }
    return true;
}

bool ProfilingWorker::Process() {
    // Выбираем все данные, покуда там вообще чо-то есть
    while (true) {
        zmq::message_t msg;
        if (!zmqListener->recv(msg, zmq::recv_flags::dontwait)) { break; }


        LOG_F(WARNING, "++ GOT DATA!");
    }
    return true;
}
} // namespace ICARUS
