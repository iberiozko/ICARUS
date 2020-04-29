#include "../CONFIG.h"
#include "loguru/loguru.hpp"
#include "heartbeatworker.h"
namespace ICARUS {

bool HeartbeatWorker::Initialize() { return true; }
bool HeartbeatWorker::Finalize() { return true; }

bool HeartbeatWorker::Process() {
    LOG_F(INFO, "Heart is alive, tick %llu, now %f, %d", cycle, now);
    return true;
}

} // namespace ICARUS
