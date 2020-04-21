#ifndef HOUSEKEEPERWORKER_H
#define HOUSEKEEPERWORKER_H
#include "../CONFIG.h"
#include "../worker.h"
namespace ICARUS {

class HousekeeperWorker : protected Worker {

protected:
    bool Initialize();
    bool Finalize();
    bool Process();
};

} // namespace ICARUS
#endif // HOUSEKEEPERWORKER_H
