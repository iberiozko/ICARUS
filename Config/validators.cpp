#include "CONFIG.h"
#include "loguru/loguru.hpp"
#include "validators.h"
namespace ICARUS {
namespace Config {

bool validateString(std::string &target, const rapidjson::Value &value, const std::string &context, const std::string &key, bool required) {
    if (!value.HasMember(key.c_str())) {
        if (required) { LOG_F(ERROR, "Configuration: %s%s required, but missing!", context.c_str(), key.c_str()); return false; }
    }
    else {
        if (!value[key.c_str()].IsString()) { LOG_F(ERROR, "Configuration: %s%s should be a string!", context.c_str(), key.c_str()); return false; }
        target = value[key.c_str()].GetString();
    }
    return true;
}

bool validateBool(bool &target, const rapidjson::Value &value, const std::string &context, const std::string &key, bool required) {
    if (!value.HasMember(key.c_str())) {
        if (required) { LOG_F(ERROR, "Configuration: %s%s required, but missing!", context.c_str(), key.c_str()); return false; }
    }
    else {
        if (!value[key.c_str()].IsBool()) { LOG_F(ERROR, "Configuration: %s%s should be a boolean!", context.c_str(), key.c_str()); return false; }
        target = value[key.c_str()].GetBool();
    }
    return true;
}

bool validateInt(int &target, const rapidjson::Value &value, const std::string &context, const std::string &key, bool required, const int minimum, const int maximum) {
    if (!value.HasMember(key.c_str())) {
        if (required) { LOG_F(ERROR, "Configuration: %s%s required, but missing!", context.c_str(), key.c_str()); return false; }
    }
    else {
        if (!value[key.c_str()].IsInt()) { LOG_F(ERROR, "Configuration: %s%s should be of type: int", context.c_str(), key.c_str()); return false; }
        int result = value[key.c_str()].GetInt();
        // Проверяемся на минимум-максимум
        if (result < minimum) { LOG_F(ERROR, "Configuration: %s%s value is below allowed minimum!", context.c_str(), key.c_str()); return false; }
        if (result > maximum) { LOG_F(ERROR, "Configuration: %s%s value is above allowed maximum!", context.c_str(), key.c_str()); return false; }
        target = result;
    }
    return true;
}

bool validateDouble(double &target, const rapidjson::Value &value, const std::string &context, const std::string &key, bool required, const double minimum, const double maximum) {
    if (!value.HasMember(key.c_str())) {
        if (required) { LOG_F(ERROR, "Configuration: %s%s required, but missing!", context.c_str(), key.c_str()); return false; }
    }
    else {
        if (!value[key.c_str()].IsDouble()) { LOG_F(ERROR, "Configuration: %s%s should be of type: double", context.c_str(), key.c_str()); return false; }
        double result = value[key.c_str()].GetDouble();
        // Проверяемся на минимум-максимум
        if (result < minimum) { LOG_F(ERROR, "Configuration: %s%s value is below allowed minimum!", context.c_str(), key.c_str()); return false; }
        if (result > maximum) { LOG_F(ERROR, "Configuration: %s%s value is above allowed maximum!", context.c_str(), key.c_str()); return false; }
        target = result;
    }
    return true;
}

bool checkObject(const rapidjson::Value &value, const std::string &context, const std::string &key, bool required) {
    if (!value.HasMember(key.c_str())) {
        if (required) { LOG_F(ERROR, "Configuration: %s%s required, but missing!", context.c_str(), key.c_str()); }
        return false;
    }
    else {
        if (!value[key.c_str()].IsObject()) { LOG_F(ERROR, "Configuration: %s%s should be of type: object", context.c_str(), key.c_str()); return false; }
        return true;
    }
}

} // namespace Config
} // namespace ICARUS
