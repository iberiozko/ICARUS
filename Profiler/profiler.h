#pragma once
#ifndef PROFILER_H
#define PROFILER_H
#include "../CONFIG.h"
#include <string>
#include <queue>
#include <map>
namespace ICARUS {
namespace Profiler {

class TickCounter {
public:
    inline void tick(double now) { holder.push(now); ++total; }
    inline void expire(double now) { while (holder.front() < now - PROFILING_INTERVAL) { holder.pop(); } };
    inline long long value() { return holder.size(); }
private:
    std::queue<double> holder;
    long long total = 0;
};

class Profiler {
public:
    inline void begin(const double currentNow) {
        now = currentNow;
        for (auto it = ticks.begin(); it != ticks.end(); ++it) { it->second.expire(now); }
    }
    inline void tick(const std::string &key) { ticks.insert(ticks.begin(), std::pair<std::string, TickCounter>(key, TickCounter()))->second.tick(now); }

    inline void push(const std::string &key, const double value) {}
    inline void setName(const std::string &n) { name = n; }

private:
    double now = 0;
    std::string name = "";
    std::map<std::string, TickCounter> ticks;
};

} // namespace Profiler
} // namespace ICARUS
#endif // PROFILER_H
