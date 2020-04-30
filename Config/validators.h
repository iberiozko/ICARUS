#pragma once
#ifndef VALIDATORS_H
#define VALIDATORS_H
#include "CONFIG.h"
#include <string>
#include "loguru/loguru.hpp"
#include "rapidjson/include/rapidjson/document.h" // Подключаем библиотеку разбора JSON-а
namespace ICARUS {
namespace Config {

bool validateString(std::string &target, const rapidjson::Value &value, const std::string &context, const std::string &key, bool required);
bool validateBool(bool &target, const rapidjson::Value &value, const std::string &context, const std::string &key, bool required);
bool validateInt(int &target, const rapidjson::Value &value, const std::string &context, const std::string &key, bool required, const int minimum = std::numeric_limits<int>::min(), const int maximum = std::numeric_limits<int>::max());
bool validateDouble(double &target, const rapidjson::Value &value, const std::string &context, const std::string &key, bool required, const double minimum = std::numeric_limits<double>::min(), const double maximum = std::numeric_limits<double>::max());
bool checkObject(const rapidjson::Value &value, const std::string &context, const std::string &key, bool required);
bool checkList(const rapidjson::Value &value, const std::string &context, const std::string &key, bool required, int fixedSize = -1);

} // namespace Config
} // namespace ICARUS
#endif // VALIDATORS_H
