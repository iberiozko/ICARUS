#pragma once
#ifndef CONFIGURATIONSECTION_H
#define CONFIGURATIONSECTION_H
#include "CONFIG.h"
#include <QVariant>
#include <QVariantMap>
#include <QVariantList>
#include "rapidjson/include/rapidjson/document.h" // Подключаем библиотеку разбора JSON-а
namespace ICARUS {
namespace Config {

class ConfigurationSection {
public:
    bool parseJsonValue(rapidjson::Value doc);
    QVariant toVariant();
    bool testMode = false;
};

} // namespace Config
} // namespace ICARUS
#endif // CONFIGURATIONSECTION_H
