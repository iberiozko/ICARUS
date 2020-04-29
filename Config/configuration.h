#pragma once
#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#include "CONFIG.h"
#include <string>
#include "rapidjson/include/rapidjson/document.h" // Подключаем библиотеку разбора JSON-а
#include "configurationsection.h"
#include "hardware.h"
#include "loggingoptions.h"
#include "heartbeat.h"
#include "housekeeper.h"
#include "gui.h"
#include "workercfg.h"
namespace ICARUS {
namespace Config {

class Configuration : public ConfigurationSection {
public:
    Configuration(const std::string configFilename);
    bool parseJsonValue(rapidjson::Value doc);

    std::string guid;
    std::string systemName = "ICARUS debug system";
    std::string systemType = "ICARUS debug installation";
    std::string systemModel = "ICARUS debug hardware";
    bool testMode = false;
    Hardware hardware;
    LoggingOptions loggingOptions;
    Heartbeat heartbeat;
    Housekeeper housekeeper;
    GUI gui;

private:
    std::string configFilename = "icarus.json";
    rapidjson::Document configDocument;
};

} // namespace Config
} // namespace ICARUS
#endif // CONFIGURATION_H
