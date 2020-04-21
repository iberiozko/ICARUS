#pragma once
#ifndef HEARTBEAT_H
#define HEARTBEAT_H
#include "../CONFIG.h"
#include "rapidjson/include/rapidjson/document.h" // Подключаем библиотеку разбора JSON-а
#include "configurationsection.h"
#include "workercfg.h"
namespace ICARUS {
namespace Config {

class Heartbeat : public ConfigurationSection {
public:
    bool enabled = false;
    WorkerCfg workerCfg = { 1.0, 0, 0, 0, true, "heartbeat" };
    bool parseJsonValue(rapidjson::Value doc);
};

} // namespace Config
} // namespace ICARUS
#endif // HEARTBEAT_H
