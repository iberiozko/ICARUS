#ifndef HEARTBEATWORKER_H
#define HEARTBEATWORKER_H
#include "../CONFIG.h"
#include "../worker.h"
namespace ICARUS {

class HeartbeatWorker : protected Worker {

protected:
    bool Initialize();
    bool Finalize();
    bool Process();

};

} // namespace ICARUS
#endif // HEARTBEATWORKER_H
