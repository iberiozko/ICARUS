#include "CONFIG.h"
#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <unistd.h>
#include "loguru/loguru.hpp"
#include "validators.h"
#include "configurationsection.h"
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

    // Конфигурационные секции
    if (checkObject(doc, "", "loggingOptions", false)) { result = loggingOptions.parseJsonValue(doc["loggingOptions"].GetObject()) && result; }
    if (checkObject(doc, "", "heartbeat", false)) { result = heartbeat.parseJsonValue(doc["heartbeat"].GetObject()) && result; }
    if (checkObject(doc, "", "housekeeper", false)) {result = housekeeper.parseJsonValue(doc["housekeeper"].GetObject()) && result; }
    if (checkObject(doc, "", "gui", false)) {result = gui.parseJsonValue(doc["gui"].GetObject()) && result; }

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

QVariant Configuration::toVariant() {
    QVariantMap map;
    map.insert("guid", QString(guid.c_str()));
    map.insert("systemName", QString(systemName.c_str()));
    map.insert("systemType", QString(systemType.c_str()));
    map.insert("systemModel", QString(systemModel.c_str()));
    map.insert("testMode", testMode);
    map.insert("hardware", hardware.toVariant());
    map.insert("loggingOptions", loggingOptions.toVariant());
    map.insert("heartbeat", heartbeat.toVariant());
    map.insert("housekeeper", housekeeper.toVariant());
    map.insert("gui", gui.toVariant());
    return QVariant(map);
}

} // namespace Config
} // namespace ICARUS
