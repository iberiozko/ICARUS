#include "../../CONFIG.h"
#include "consoleevent.h"
namespace ICARUS {
namespace Msg {

ConsoleEvent::ConsoleEvent(const std::map<std::string, std::pair<double, bool>> &source) {
    for (auto it = source.begin(); it != source.end(); ++it) {
        Proto::ConsoleSignal *signal = add_event();
        signal->set_signal(it->first);
        if (it->second.second) { signal->set_value(it->second.first); }
    }
}

ConsoleEvent::ConsoleEvent(const QVariantMap &source) {
    for (auto it = source.begin(); it != source.end(); ++it) {
        Proto::ConsoleSignal *signal = add_event();
        signal->set_signal(it.key().toStdString());
        if (it.value().isValid()) { signal->set_value(it.value().toDouble()); }
    }
}

const QVariant ConsoleEvent::toVariant() {
    QVariantMap result;
    for (int i = 0; i < event_size(); i++) {
        const Proto::ConsoleSignal &signal = event(i);
        if (signal.has_value()) { result.insert(QString(signal.signal().c_str()), QVariant(signal.value())); }
        else { result.insert(QString(signal.signal().c_str()), QVariant()); }
    }
    return QVariant(result);
}

const std::map<std::string, std::pair<double, bool>> ConsoleEvent::toStdMap() {
    std::map<std::string, std::pair<double, bool>> result;
    for (int i = 0; i < event_size(); i++) {
        const Proto::ConsoleSignal &signal = event(i);
        if (signal.has_value()) { result.insert(std::pair<std::string, std::pair<double, bool>>(signal.signal(), std::pair<double, bool>(signal.value(), true))); }
        else { result.insert(std::pair<std::string, std::pair<double, bool>>(signal.signal(), std::pair<double, bool>(0.0, false))); }
    }
    return result;
}

} // namespace Msg
} // namespace ICARUS
