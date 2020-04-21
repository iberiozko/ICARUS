#pragma once
#ifndef HOUSEKEEPER_H
#define HOUSEKEEPER_H
#include "CONFIG.h"
#include "rapidjson/include/rapidjson/document.h" // Подключаем библиотеку разбора JSON-а
#include "configurationsection.h"
#include "workercfg.h"
namespace ICARUS {
namespace Config {

class Housekeeper : public ConfigurationSection {
public:
    bool enabled = false;
    WorkerCfg workerCfg = { 5.0, 10, 10, 10, false, "housekeeper" };

    bool parseJsonValue(rapidjson::Value doc);
};

} // namespace Config
} // namespace ICARUS
#endif // HOUSEKEEPER_H
