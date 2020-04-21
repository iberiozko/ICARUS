#include "CONFIG.h"
#include <unistd.h>
#include <sys/time.h>
#include <thread>
#include "loguru/loguru.hpp"
#include "worker.h"
namespace ICARUS {

void Worker::Run() {
    std::thread worker([this] { this->Tick(); });
    workingThread.swap(worker);
}

void Worker::Tick() {
    loguru::set_thread_name(workerCfg.friendlyName.c_str());
    LOG_F(INFO, "Worker thread for '%s' starting...", workerCfg.friendlyName.c_str());
    running = true;

    // Входим в рабочий цикл
    int init_counter = 0;
    int fin_counter = 0;
    int process_counter = 0;
    state = INIT;
    while (running) {
        // Продвигаем текущее время и номер такта
        now = getCurrentNow();
        ++cycle;

        // Обрабатываем машину состояний (QtCreator совершенно дебильно форматирует switch (: )
        switch (state) {
        // В панике - завершаемся с ужосом :)
        case PANIC:
            running = false;
            LOG_F(ERROR, "Terminating on PANIC state!");
            break;

        // В инициализации - делаем, но ловим на всякий случай еще и исключения
        case INIT:
            try {
                if (Initialize()) {
                    state = RUN;
                    LOG_F(INFO, "Initialized successfully after %d attempts", init_counter);
                    init_counter = 0;
                }
                else {
                    ++init_counter;
                    if (workerCfg.maxInitializeRetries > 0 && init_counter > workerCfg.maxInitializeRetries) {
                        state = FIN;
                        LOG_F(ERROR, "Excedeed max number of initialize attempts: %d", init_counter);
                        init_counter = 0;
                    }
                }
            }
            catch (...) {
                state = PANIC;
                LOG_F(ERROR, "Got exception in initialization!");
                init_counter = 0;
            }
            break;

        // В финализации - аналогично
        case FIN:
            try {
                if (Finalize()) {
                    state = INIT;
                    LOG_F(INFO, "Finalized successfuly...");
                    fin_counter = 0;
                }
                else {
                    ++fin_counter;
                    if (workerCfg.maxFinalizeRetries > 0 && fin_counter > workerCfg.maxFinalizeRetries) {
                        state = PANIC;
                        LOG_F(ERROR, "Exceeded max number of finalize attempts: %d", fin_counter);
                        fin_counter = 0;
                    }
                }
            }
            catch (...) {
                state = PANIC;
                LOG_F(ERROR, "Got excepterion in finalization!");
                fin_counter = 0;
            }
            break;

        case RUN:
            try {
                if (Process()) { process_counter = 0; }
                else {
                    ++process_counter;
                    if (workerCfg.maxProcessRetries > 0 && process_counter > workerCfg.maxProcessRetries) {
                        state = FIN;
                        LOG_F(ERROR, "Exceeded max number of tick process attempts: %d", process_counter);
                        process_counter = 0;
                    }
                }
            }
            catch (...) {
                state = PANIC;
                LOG_F(ERROR, "Got exception while processing tick!");
                process_counter = 0;
            }
        }

        // Разбираемся, сколько мы были в разработчике...
        double elapsed = getCurrentNow() - now;
        if (elapsed > sleeptime) {
            if (sleeptime > 0.0) { LOG_F(ERROR, "Cycle length overrun, cycle elapsed: %f, overrun is: %f", elapsed, elapsed - sleeptime); }
        }
        else {
            usleep((sleeptime - elapsed) / 1000000.0);
        }
    }
    LOG_F(WARNING, "Worker thread for '%s' terminating...", workerCfg.friendlyName.c_str());
}

// Это хитрая получалочка текущего таймстемпа (вовсе не времени)
double Worker::getCurrentNow() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    if (0 == epoch) { epoch = tv.tv_sec; }
    return (double)(tv.tv_sec - epoch) + (double)tv.tv_usec / 1000000.0;
}

} // namespace ICARUS
