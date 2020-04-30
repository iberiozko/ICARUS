QT += quick virtualkeyboard

CONFIG += c++17
QMAKE_LIBS += -ldl -lprotobuf

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Config/configuration.cpp \
        Config/gui.cpp \
        Config/hardware.cpp \
        Config/heartbeat.cpp \
        Config/housekeeper.cpp \
        Config/loggingoptions.cpp \
        Config/profiling.cpp \
        Config/validators.cpp \
        Config/workercfg.cpp \
        GUI/guiworker.cpp \
        GUI/logger.cpp \
        Heartbeat/heartbeatworker.cpp \
        Housekeeper/housekeeperworker.cpp \
        Profiler/profiler.cpp \
        Profiler/profilingworker.cpp \
        Proto/ConsoleEvent/ConsoleEvent.pb.cc \
        Proto/ConsoleEvent/consoleevent.cpp \
        Proto/HeartbeatEvent/HeartbeatEvent.pb.cc \
        Proto/HeartbeatEvent/heartbeatevent.cpp \
        Proto/ProfilingEvent/ProfilingEvent.pb.cc \
        Proto/ProfilingEvent/profilingevent.cpp \
        loguru/loguru.cpp \
        main.cpp \
        options.cpp \
        supervisor.cpp \
        worker.cpp

RESOURCES += \
    QML/Builtin.qrc

TRANSLATIONS += \
    ICARUS_ru_RU.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    CONFIG.h \
    Config/configuration.h \
    Config/configurationsection.h \
    Config/gui.h \
    Config/hardware.h \
    Config/heartbeat.h \
    Config/housekeeper.h \
    Config/loggingoptions.h \
    Config/profiling.h \
    Config/validators.h \
    Config/workercfg.h \
    GUI/guiworker.h \
    GUI/logger.h \
    Heartbeat/heartbeatworker.h \
    Housekeeper/housekeeperworker.h \
    Profiler/profiler.h \
    Profiler/profilingworker.h \
    Proto/ConsoleEvent/ConsoleEvent.pb.h \
    Proto/ConsoleEvent/consoleevent.h \
    Proto/HeartbeatEvent/HeartbeatEvent.pb.h \
    Proto/HeartbeatEvent/heartbeatevent.h \
    Proto/ProfilingEvent/ProfilingEvent.pb.h \
    Proto/ProfilingEvent/profilingevent.h \
    cppzmq/zmq.hpp \
    loguru/loguru.hpp \
    options.h \
    rapidjson/include/rapidjson/document.h \
    supervisor.h \
    worker.h

DISTFILES += \
    Proto/ConsoleEvent/ConsoleEvent.proto \
    Proto/Heartbeat/HeartbeatEvent.proto \
    Proto/HeartbeatEvent/HeartbeatEvent.proto \
    Proto/ProfilingEvent/ProfilingEvent.proto

unix:!macx: LIBS += -L$$PWD/build-libzmq-Desktop_Qt_5_14_1_GCC_64bit-Debug/lib/ -lzmq

INCLUDEPATH += $$PWD/libzmq/include
DEPENDPATH += $$PWD/libzmq/include

unix:!macx: PRE_TARGETDEPS += $$PWD/build-libzmq-Desktop_Qt_5_14_1_GCC_64bit-Debug/lib/libzmq.a
