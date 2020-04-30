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

class GUIScreen : public ConfigurationSection {
public:
    bool enabled = false;
    bool fullScreen = false;
    int screenId = 0;
    int x = 0;
    int y = 0;
    int width = 640;
    int height = 480;
    std::string bootstrap = "qrc:/Testmode/Testmode.qml";
    std::string application = "";
    bool parseJsonValue(rapidjson::Value doc);
    QVariant toVariant();
};

class GUI : public ConfigurationSection {
public:
    bool enabled = false;
    WorkerCfg workerCfg = { 100.0, 0, 0, 0, true, "gui" };
    std::list<GUIScreen> screens;
    bool parseJsonValue(rapidjson::Value doc);
    QVariant toVariant();
};

} // namespace Config
} // namespace ICARUS
#endif // GUI_H
