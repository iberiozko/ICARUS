#include "CONFIG.h"
#ifdef __linux__
#include <sys/utsname.h>
#else
#error Only linux is implemented!
#endif
#include "loguru/loguru.hpp"
#include "hardware.h"
namespace ICARUS {
namespace Config {

QVariant Hardware::toVariant() {
    QVariantMap map;
    map.insert("sysname", QString(sysname.c_str()));
    map.insert("nodename", QString(nodename.c_str()));
    map.insert("release", QString(release.c_str()));
    map.insert("version", QString(version.c_str()));
    map.insert("machine", QString(machine.c_str()));
    return QVariant(map);
}

void Hardware::collectHardware() {
#ifdef __linux__
    // На линухе берем из UTS
    struct utsname buf;
    if (0 == uname(&buf)) {
        sysname = buf.sysname;
        nodename = buf.nodename;
        release = buf.release;
        version = buf.version;
        machine = buf.machine;
    }
    else { LOG_F(ERROR, "Failed to get UTS system information, data will be unknown, ignoring..."); }
#else
#endif

    LOG_F(INFO, "Detected system information:");
    LOG_F(INFO, "    sysname: %s", sysname.c_str());
    LOG_F(INFO, "    nodename: %s", nodename.c_str());
    LOG_F(INFO, "    release: %s", release.c_str());
    LOG_F(INFO, "    version: %s", version.c_str());
    LOG_F(INFO, "    machine: %s", machine.c_str());
}

} // namespace Config
} // namespace ICARUS
