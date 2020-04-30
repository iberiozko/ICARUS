#pragma once
#ifndef PROFILING_H
#define PROFILING_H
#include "CONFIG.h"
#include "rapidjson/include/rapidjson/document.h" // Подключаем библиотеку разбора JSON-а
#include "configurationsection.h"
#include "workercfg.h"
namespace ICARUS {
namespace Config {

class Profiling : public ConfigurationSection {
public:
    bool enabled = true;
    WorkerCfg workerCfg = { 10.0, 0, 0, 0, true, "profiling" };
    bool parseJsonValue(rapidjson::Value doc);
    QVariant toVariant();
};

} // namespace Config
} // namespace ICARUS
#endif // PROFILING_H
