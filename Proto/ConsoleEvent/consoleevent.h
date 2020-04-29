#pragma once
#ifndef CONSOLEEVENT_H
#define CONSOLEEVENT_H
#include "../../CONFIG.h"
#include "ConsoleEvent.pb.h"
#include <QVariantMap>
namespace ICARUS {
namespace Msg {

class ConsoleEvent : public Proto::ConsoleEvent {
public:
    ConsoleEvent(const std::map<std::string, std::pair<double, bool>> &source);
    ConsoleEvent(const QVariantMap &source);
    const QVariant toVariant();
    const std::map<std::string, std::pair<double, bool>> toStdMap();
};

} // namespace Msg
} // namespace ICARUS
#endif // CONSOLEEVENT_H
