#include "CONFIG.h"
#include <unistd.h>
#include <thread>
#include "loguru/loguru.hpp"
#include "supervisor.h"
namespace ICARUS {

void Supervisor::start() {
    LOG_F(INFO, "Starting main supervisor thread...");
    std::thread worker([this] { this->supervise(); });
    workingThread.swap(worker);
}

void Supervisor::supervise() {
    loguru::set_thread_name("supervisor");
    LOG_F(INFO, "Entering working thread...");

    // Вертимся пока дают...
    while(running) {
        LOG_F(INFO, "supervisor tick...");
        usleep(SUPERVISOR_SLEEPTIME_MKS);
    }

    LOG_F(WARNING, "Working thread terminated");
}

} // namespace ICARUS
