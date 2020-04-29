#pragma once
#ifndef GUI_H
#define GUI_H
#include "CONFIG.h"
#include <string>
#include "rapidjson/include/rapidjson/document.h" // Подключаем библиотеку разбора JSON-а
#include "configurationsection.h"
#include "workercfg.h"
namespace ICARUS {
namespace Config {

class GUI : public ConfigurationSection {
public:
    bool enabled = false;
    WorkerCfg workerCfg = { 100.0, 0, 0, 0, true, "gui" };
    bool parseJsonValue(rapidjson::Value doc);
};

} // namespace Config
} // namespace ICARUS
#endif // GUI_H
