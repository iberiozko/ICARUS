#pragma once
#ifndef LOGGINGOPTIONS_H
#define LOGGINGOPTIONS_H
#include "CONFIG.h"
#include "rapidjson/include/rapidjson/document.h" // Подключаем библиотеку разбора JSON-а
#include "configurationsection.h"
namespace ICARUS {
namespace Config {

class LoggingOptions : public ConfigurationSection {
public:
    int stderrVerbosity = 0; // this is INFO for loguru
    bool colorLogToStderr = true;
    int flushIntervalMs = 25;
    bool preambleHeader = true;
    bool preamble = true;
    bool preambleDate = true;
    bool preambleTime = true;
    bool preambleUptime = false;
    bool preambleThread = true;
    bool preambleFile = false;
    bool preambleVerbose = true;
    bool preamblePipe = true;
    std::string filePath = "";
    int fileVerbosity = 0;

    bool parseJsonValue(rapidjson::Value doc);
    QVariant toVariant();
    void configureLogging();
};

} // namespace Config
} // namespace ICARUS
#endif // LOGGINGOPTIONS_H
