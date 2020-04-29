#include "../../CONFIG.h"
#include <QVariantMap>
#include "heartbeatevent.h"
namespace ICARUS {
namespace Msg {

HeartbeatEvent::HeartbeatEvent(const Config::Configuration &config) {
    set_guid(config.guid);
    set_systemname(config.systemName);
    set_systemtype(config.systemType);
    set_systemmodel(config.systemModel);
    mutable_hardware()->set_sysname(config.hardware.sysname);
    mutable_hardware()->set_nodename(config.hardware.nodename);
    mutable_hardware()->set_release(config.hardware.release);
    mutable_hardware()->set_version(config.hardware.version);
    mutable_hardware()->set_machine(config.hardware.machine);
}

const QVariant HeartbeatEvent::toVariant() {
    QVariantMap result;
    result.insert("guid", QVariant(QString(guid().c_str())));
    result.insert("systemName", QVariant(QString(systemname().c_str())));
    result.insert("systemType", QVariant(QString(systemtype().c_str())));
    result.insert("systemModel", QVariant(QString(systemmodel().c_str())));
    QVariantMap hw;
    hw.insert("sysname", QVariant(QString(hardware().sysname().c_str())));
    hw.insert("nodename", QVariant(QString(hardware().nodename().c_str())));
    hw.insert("release", QVariant(QString(hardware().release().c_str())));
    hw.insert("version", QVariant(QString(hardware().version().c_str())));
    hw.insert("machine", QVariant(QString(hardware().machine().c_str())));
    result.insert("hardwre", hw);
    return QVariant(result);
}

} // namespace Msg
} // namespace ICARUS
