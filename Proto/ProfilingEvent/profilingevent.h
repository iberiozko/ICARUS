#pragma once
#ifndef PROFILINGEVENT_H
#define PROFILINGEVENT_H
#include "../../CONFIG.h"
#include <QVariant>
#include "ProfilingEvent.pb.h"
namespace ICARUS {
namespace Msg {

class ProfilingShortEvent : public Proto::ProfilingShortEvent {
public:
    ProfilingShortEvent(const std::map<std::string, double> &ticks, const std::string &name, const double delta);
};

} // namespace Msg
} // namespace ICARUS
#endif // PROFILINGEVENT_H
