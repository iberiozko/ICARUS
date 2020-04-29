#pragma once
#ifndef WORKERCFG_H
#define WORKERCFG_H
#include "CONFIG.h"
#include <cstdint>
#include <string>
#include "rapidjson/include/rapidjson/document.h" // Подключаем библиотеку разбора JSON-а
#include "configurationsection.h"
namespace ICARUS {
namespace Config {

class WorkerCfg : public ConfigurationSection {
public:
    WorkerCfg(double hz, uint32_t maxInitializeRetries, uint32_t maxFinalizeRetries, uint32_t maxProcessRetries, bool testMode, const std::string &name) :
        hz(hz),
        maxInitializeRetries(maxInitializeRetries),
        maxFinalizeRetries(maxFinalizeRetries),
        maxProcessRetries(maxProcessRetries),
        testMode(testMode),
        name(name)
    {}

    double hz;
    int maxInitializeRetries;
    int maxFinalizeRetries;
    int maxProcessRetries;
    bool testMode;
    std::string name;

    bool parseJsonValue(rapidjson::Value doc);
};

} // namespace Config
} // namespace ICARUS
#endif // WORKERCFG_H
