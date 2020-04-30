#pragma once
#ifndef HEARTBEATEVENT_H
#define HEARTBEATEVENT_H
#include "../../CONFIG.h"
#include <QVariant>
#include "../../Config/configuration.h"
#include "HeartbeatEvent.pb.h"
namespace ICARUS {
namespace Msg {

class HeartbeatEvent : public Proto::HeartbeatEvent {
public:
    HeartbeatEvent(const Config::Configuration &config);
    const QVariant toVariant();
};

} // namespace Msg
} // namespace ICARUS
#endif // HEARTBEATEVENT_H
