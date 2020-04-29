#ifndef HOUSEKEEPERWORKER_H
#define HOUSEKEEPERWORKER_H
#include "../CONFIG.h"
#include "../Config/configuration.h"
#include "../worker.h"
namespace ICARUS {

class HousekeeperWorker : public Worker {
public:
    HousekeeperWorker(Config::Configuration &globalConfig, Config::Housekeeper &config) : Worker(globalConfig, config.workerCfg), config(config) {}

protected:
    bool Initialize() override;
    bool Finalize() override;
    bool Process() override;

private:
    Config::Housekeeper config;
};

} // namespace ICARUS
#endif // HOUSEKEEPERWORKER_H
