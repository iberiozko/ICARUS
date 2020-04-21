#include "CONFIG.h"
#include "loguru/loguru.hpp"
#include "loggingoptions.h"
#include "validators.h"
namespace ICARUS {
namespace Config {

bool LoggingOptions::parseJsonValue(rapidjson::Value doc) {
    bool result = true;
    result = validateInt(stderrVerbosity, doc, "loggingOptions", "stderrVerbosity", false, -2, 9) && result;
    result = validateBool(colorLogToStderr, doc, "loggingOptions.", "colorLogToStderr", false) && result;
    result = validateInt(flushIntervalMs, doc, "loggingOptions", "flushIntervalMs", false, 0, 1000) && result;
    result = validateBool(preambleHeader, doc, "loggingOptions.", "preambleHeader", false) && result;
    result = validateBool(preamble, doc, "loggingOptions.", "preamble", false) && result;
    result = validateBool(preambleDate, doc, "loggingOptions.", "preambleDate", false) && result;
    result = validateBool(preambleTime, doc, "loggingOptions.", "preambleTime", false) && result;
    result = validateBool(preambleUptime, doc, "loggingOptions.", "preambleUptime", false) && result;
    result = validateBool(preambleThread, doc, "loggingOptions.", "preambleThread", false) && result;
    result = validateBool(preambleFile, doc, "loggingOptions.", "preambleFile", false) && result;
    result = validateBool(preambleVerbose, doc, "loggingOptions.", "preambleVerbose", false) && result;
    result = validateBool(preamblePipe, doc, "loggingOptions.", "preamblePipe", false) && result;
    result = validateInt(fileVerbosity, doc, "loggingOptions", "fileVerbosity", false, -2, 9) && result;
    result = validateString(filePath, doc, "loggingOptions.", "filePath", false) && result;
    return result;
}

void LoggingOptions::configureLogging() {
    // Перебрасываем в библиотеку логгирования опции конфигурации
    loguru::g_stderr_verbosity      = stderrVerbosity;
    loguru::g_colorlogtostderr      = colorLogToStderr;
    loguru::g_flush_interval_ms     = flushIntervalMs;
    loguru::g_preamble_header       = preambleHeader;
    loguru::g_preamble              = preamble;
    loguru::g_preamble_date         = preambleDate;
    loguru::g_preamble_time         = preambleTime;
    loguru::g_preamble_uptime       = preambleUptime;
    loguru::g_preamble_thread       = preambleThread;
    loguru::g_preamble_file         = preambleFile;
    loguru::g_preamble_verbose      = preambleVerbose;
    loguru::g_preamble_pipe         = preamblePipe;
}

} // namespace Config
} // namespace ICARUS
