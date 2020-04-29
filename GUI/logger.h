#ifndef LOGGER_H
#define LOGGER_H
#include "../CONFIG.h"
#include "loguru/loguru.hpp"
#include <QObject>
#include <stdarg.h>
namespace ICARUS {
namespace GUI {

class Logger : public QObject {
    Q_OBJECT
public:
//    Q_INVOKABLE inline void info(QString fmt) { va_list args; LOG_F(INFO, fmt.toLatin1(), args); }
//    Q_INVOKABLE inline void warning(QString fmt, ...) { LOG_F(WARNING, fmt.toStdString().c_str()); }
//    Q_INVOKABLE inline void error(QString fmt) { OG_F(ERROR, fmt.toLatin1(), args); }

};

} // namespace GUI
} // namespace ICARUS
#endif // LOGGER_H
