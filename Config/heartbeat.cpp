#include "../CONFIG.h"
#include "loguru/loguru.hpp"
#include "validators.h"
#include "heartbeat.h"
namespace ICARUS {
namespace Config {

bool Heartbeat::parseJsonValue(rapidjson::Value doc) {
    bool result = true;
    result = validateBool(enabled, doc, "housekeeper.", "hz", false) && result;
    if (doc.HasMember("workerCfg")) {
        if (doc["workerCfg"].IsObject()) {
            result = workerCfg.parseJsonValue(doc["workerCfg"].GetObject()) && result;
        }
        else { LOG_F(ERROR, "Configuration: workerCfg section should be an object!"); result = false; }
    }
    return result;
}

} // namespace Config
} // namespace ICARUS
