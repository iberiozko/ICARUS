#include "profiling.h"
#include "validators.h"
namespace ICARUS {
namespace Config {

bool Profiling::parseJsonValue(rapidjson::Value doc) {
    bool result = true;
    result = validateBool(enabled, doc, "profiling.", "enabled", false) && result;
    if (checkObject(doc, "profiling.", "workerCfg", false)) { result = workerCfg.parseJsonValue(doc["workerCfg"].GetObject()) && result; }
    return result;
}

QVariant Profiling::toVariant() {
    QVariantMap map;
    map.insert("enabled", enabled);
    map.insert("workerCfg", workerCfg.toVariant());
    return QVariant(map);
}

} // namespace Config
} // namespace ICARUS
