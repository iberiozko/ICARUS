#pragma once
#ifndef PROFILER_H
#define PROFILER_H
#include "../CONFIG.h"
#include <string>
#include <map>
#include "loguru/loguru.hpp"
#include "cppzmq/zmq.hpp"
#include "../Proto/ProfilingEvent/profilingevent.h"
namespace ICARUS {
namespace Profiler {

class Profiler {
public:
    Profiler() {
        zmqSender = new zmq::socket_t(zmqContext, zmq::socket_type::pub);
        try { zmqSender->connect(PROFILING_ZMQ_SOCKET); }
        catch (const std::exception &e) {
            LOG_F(ERROR, "Failed to initialize profiling socket: %s: %s", PROFILING_ZMQ_SOCKET.c_str(), e.what());
            throw(e);
        }
    }
    inline void setName(const std::string &n) { name = n; }

    void begin(const double now) {
        // Если пришел срок сброса короткого интервала, то сбрасываем его (если сокет не подключен - не няпрягаемся)
        if (zmqSender->connected() && (now - lastFlushNow > PROFILING_SHORT_INTERVAL)) {
            // Конструируем сообщение и пытаемся его отослать
            Msg::ProfilingShortEvent event(ticks, name, now - lastFlushNow);
            try {
                const std::string buffer = event.SerializeAsString();
                zmq::message_t msg(buffer.length());
                memcpy(msg.data(), buffer.c_str(), buffer.length());
                zmqSender->send(msg, zmq::send_flags::dontwait);
            }
            catch (const std::exception &e) { LOG_F(ERROR, "Failed to send profiling data: %s", e.what()); return; }
            // Если все удалось - начинаем аггрегировать сначала
            for (auto it = ticks.begin(); it != ticks.end(); ++it) { it->second = 0.0; }
            lastFlushNow = now;
        }
    }

    inline void tick(const std::string &key) {
        try { ticks.at(key) += 1.0; }
        catch (std::out_of_range) { ticks.insert(ticks.begin(), std::pair<std::string, double>(key, 1.0)); }
    }
    inline void push(const std::string &key, const double value) {
        try { ticks.at(key) += value; }
        catch (std::out_of_range) { ticks.insert(ticks.begin(), std::pair<std::string, double>(key, value)); }
    }

private:
    double lastFlushNow = 0;
    std::string name = "";
    std::map<std::string, double> ticks;

    zmq::context_t zmqContext{1, 1};
    zmq::socket_t *zmqSender;
};

} // namespace Profiler
} // namespace ICARUS
#endif // PROFILER_H
