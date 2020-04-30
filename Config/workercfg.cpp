#include "CONFIG.h"
#include "workercfg.h"
#include "validators.h"
namespace ICARUS {
namespace Config {

bool WorkerCfg::parseJsonValue(rapidjson::Value doc) {
    bool result = true;
    result = validateDouble(hz, doc, "workerCfg.", "hz", false, 0) && result;
    result = validateInt(maxInitializeRetries, doc, "workerCfg.", "maxInitializeRetries", false, 0) && result;
    result = validateInt(maxFinalizeRetries, doc, "workerCfg.", "maxFinalizeRetries", false, 0) && result;
    result = validateInt(maxProcessRetries, doc, "workerCfg.", "maxProcessRetries", false, 0) && result;
    result = validateBool(testMode, doc, "workerCfg.", "testMode", false) && result;
    result = validateString(name, doc, "workerCfg.", "name", false) && result;
    return result;
}

QVariant WorkerCfg::toVariant() {
    QVariantMap map;
    map.insert("hz", hz);
    map.insert("maxInitializeRetries", maxInitializeRetries);
    map.insert("maxFinalizeRetries", maxFinalizeRetries);
    map.insert("maxProcessRetries", maxProcessRetries);
    map.insert("testMode", testMode);
    map.insert("name", QString(name.c_str()));
    return QVariant(map);
}

} // namespace Config
} // namespace ICARUS
