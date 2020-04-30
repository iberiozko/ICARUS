#include "../../CONFIG.h"
#include "profilingevent.h"
namespace ICARUS {
namespace Msg {

ProfilingShortEvent::ProfilingShortEvent(const std::map<std::string, double> &ticks, const std::string &name, const double delta) {
    set_name(name);
    for (auto it = ticks.begin(); it != ticks.end(); ++it) {
        Proto::ProfilingShortItem *item = add_items();
        item->set_key(it->first);
        item->set_shortvalue(it->second);
        if (delta > 0.0) { item->set_shortaverage(it->second / delta); } else { item->set_shortaverage(0.0); }
    }
}

} // namespace Msg
} // namespace ICARUS
