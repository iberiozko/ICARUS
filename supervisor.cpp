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

    // Это наши работники, они живут имено в этом контексте
    HeartbeatWorker heartbeatWorker(config, config.heartbeat); if (config.heartbeat.enabled) { heartbeatWorker.Run(); }
    HousekeeperWorker housekeeperWorker(config, config.housekeeper); if (config.housekeeper.enabled) { housekeeperWorker.Run(); }

    // Вертимся пока дают...
    running.test_and_set();
    while(running.test_and_set()) {
        prof.tick("run");
        // LOG_F(INFO, "supervisor tick...");

        // TODO Тут нужно проверять, что у нас потоки не попадали, и переподнимать их...

        // Спим, чтобы не очень жестко грузить проц этим потоком...
        usleep(SUPERVISOR_SLEEPTIME_MKS);
    }

    LOG_F(WARNING, "Working thread terminated");
}

} // namespace ICARUS
