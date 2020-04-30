#pragma once
#ifndef HARDWARE_H
#define HARDWARE_H
#include "CONFIG.h"
#include <string>
#include "configurationsection.h"
namespace ICARUS {
namespace Config {

class Hardware : public ConfigurationSection {
public:
    std::string sysname = "unknown";
    std::string nodename = "unknown";
    std::string release = "unknown";
    std::string version = "unknown";
    std::string machine = "unknown";

    void collectHardware();
    QVariant toVariant();
};

} // namespace Config
} // namespace ICARUS
#endif // HARDWARE_H
