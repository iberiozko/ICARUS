#pragma once
#ifndef CONFIG_H
#define CONFIG_H
#include <string>

// Настройки ширины столбцов - только на стадии компиляции
#define LOGURU_FILENAME_WIDTH 24
#define LOGURU_THREADNAME_WIDTH 16
#define LOGURU_VERBOSE_SCOPE_ENDINGS 1
#define LOGURU_SCOPE_TIME_PRECISION 3
// Эта штука включает авторотацию логов - типа удалил, а он сам пересоздался
#define LOGURU_WITH_FILEABS 0

// Длительность такта супервизора (тут МИКРОсекунды!!!)
const double SUPERVISOR_SLEEPTIME_MKS = 100000;

// Сколько символов показывать в контексте ошибки разбора JSON
const int JSON_ERROR_CONTEXT_LENGTH = 50;

// Интервал профилирования, и сброса накопленной статистики, в секундах
#define PROFILING_ENABLED
const std::string PROFILING_ZMQ_SOCKET = "ipc://profiling"; //"inproc://profiling"; почему-то не работает, там баг!
const int PROFILING_ZMQ_THREADS = 1;
const int PROFILING_ZMQ_MAX_SOCKETS = 10;
const double PROFILING_SHORT_INTERVAL = 5.0; // Короткий интервал аггрегации профилирования

#endif // CONFIG_H
