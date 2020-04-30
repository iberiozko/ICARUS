#include "CONFIG.h"
#include "loguru/loguru.hpp"
#include "housekeeper.h"
#include "validators.h"
namespace ICARUS {
namespace Config {

bool Housekeeper::parseJsonValue(rapidjson::Value doc) {
    bool result = true;
    result = validateBool(enabled, doc, "housekeeper.", "enabled", false) && result;
    if (checkObject(doc, "housekeeper.", "workerCfg", false)) { result = workerCfg.parseJsonValue(doc["workerCfg"].GetObject()) && result; }
    return result;
}

QVariant Housekeeper::toVariant() {
    QVariantMap map;
    map.insert("enabled", enabled);
    map.insert("workerCfg", workerCfg.toVariant());
    return QVariant(map);
}

} // namespace Config
} // namespace ICARUS
