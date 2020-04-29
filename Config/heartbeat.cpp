#include "../CONFIG.h"
#include "loguru/loguru.hpp"
#include "validators.h"
#include "heartbeat.h"
namespace ICARUS {
namespace Config {

bool Heartbeat::parseJsonValue(rapidjson::Value doc) {
    bool result = true;
    result = validateBool(enabled, doc, "heartbeat.", "enabled", false) && result;
    if (checkObject(doc, "heartbeat.", "workerCfg", false)) { result = workerCfg.parseJsonValue(doc["workerCfg"].GetObject()) && result; }
    return result;
}

} // namespace Config
} // namespace ICARUS
