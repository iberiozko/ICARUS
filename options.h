#pragma once
#ifndef OPTIONS_H
#define OPTIONS_H
#include "CONFIG.h"
#include <string>

class Options {
public:
    Options(int argc, char *argv[]);
    bool requireDump = false;
    bool requireUpdate = false;
    bool testMode = false;
    std::string configFilename = "icarus.json";
};

#endif // OPTIONS_H
