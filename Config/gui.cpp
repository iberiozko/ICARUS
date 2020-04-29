#include "gui.h"
#include "validators.h"
namespace ICARUS {
namespace Config {

bool GUI::parseJsonValue(rapidjson::Value doc) {
    bool result = true;
    result = validateBool(enabled, doc, "gui.", "enabled", false) && result;
    if (checkObject(doc, "gui.", "workerCfg", false)) { result = workerCfg.parseJsonValue(doc["workerCfg"].GetObject()) && result; }
    return result;
}

} // namespace Config
} // namespace ICARUS
