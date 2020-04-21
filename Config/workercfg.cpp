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
    result = validateString(friendlyName, doc, "workerCfg.", "friendlyName", false) && result;
    return result;
}

} // namespace Config
} // namespace ICARUS
