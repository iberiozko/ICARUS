#include "CONFIG.h"
#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <unistd.h>
#include "loguru/loguru.hpp"
#include "validators.h"
#include "configuration.h"
namespace ICARUS {
namespace Config {

Configuration::Configuration(const std::string configFilename) : configFilename(configFilename) {
    // Загружаем документ из указанного сырца
    std::ifstream fh(configFilename);
    if (!fh) { ABORT_F("Failed to load configuration from: %s", configFilename.c_str()); }
    std::string buffer((std::istreambuf_iterator<char>(fh)), std::istreambuf_iterator<char>());
    if (buffer.empty()) { ABORT_F("Configuration file %s is empty or loading failed", configFilename.c_str()); }

    // Разбираем документ
    rapidjson::ParseResult result = configDocument.Parse(buffer.c_str());
    if (!result) {
        ABORT_F("Config parse in %s parse failed: code %d at offset %lu, just after: %s",
                configFilename.c_str(),
                result.Code(),
                result.Offset(),
                buffer.substr(result.Offset() - JSON_ERROR_CONTEXT_LENGTH, JSON_ERROR_CONTEXT_LENGTH).c_str()
                );
    }
    if (!configDocument.IsObject()) { ABORT_F("Configuration file must contain JSON object as a root item"); }
    if (!parseJsonValue(configDocument.GetObject())) { ABORT_F("Configuration file validation failed!"); }
    LOG_F(INFO, "Successfully loaded configuration from: %s", configFilename.c_str());
}

bool Configuration::parseJsonValue(rapidjson::Value doc) {
    bool result = true; // Результат разбора

    // Разбираем параметры
    result = validateString(guid, doc, "", "guid", false) && result;
    result = validateString(systemName, doc, "", "systemName", false) && result;
    result = validateString(systemType, doc, "", "systemType", false) && result;
    result = validateString(systemModel, doc, "", "systemModel", false) && result;
    result = validateBool(testMode, doc, "", "testMode", false) && result;

    // loggingOptions
    if (doc.HasMember("loggingOptions")) {
        if (doc["loggingOptions"].IsObject()) { result = loggingOptions.parseJsonValue(doc["loggingOptions"].GetObject()) && result; }
        else { LOG_F(ERROR, "loggingOptions section must be an object!"); result = false; }
    }

    // heartbeat
    if (doc.HasMember("heartbeat")) {
        if (doc["heartbeat"].IsObject()) { result = heartbeat.parseJsonValue(doc["heartbeat"].GetObject()) && result; }
        else { LOG_F(ERROR, "heartbeat: section must be an object!"); result = false; }
    }

    // Разбираемся с GUID-ом
    if (guid.empty()) {
        guid = std::to_string(gethostid());
        LOG_F(INFO, "Using system unique id as system GUID: %s", guid.c_str());
    }
    else { LOG_F(WARNING, "Using statically confugured system GUID: %s", guid.c_str()); }

    // Грузим информацию про систему
    hardware.collectHardware();

    return result; // Возвращаем, что у нас получилось
}

} // namespace Config
} // namespace ICARUS
