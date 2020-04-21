#include "CONFIG.h"
#include <iostream>
#include <getopt.h>
#include "options.h"

Options::Options(int argc, char *argv[]) {
    int c;
    while (-1 != (c = getopt(argc, argv, "c:dtuvh"))) {
        switch (c) {
            case 'c': configFilename = optarg; break;
            case 'd': requireDump = true; break;
            case 'u': requireUpdate = true; break;
            case 't': testMode = true; break;
            case 'v': break;
            default:
                std::cout << "Usage:\t" << argv[0] << " [-c config_filename.json] [-t] [-d] [-u] [-v stderr_verbosity]" << std::endl;
                std::cout << "\t-d - parse and dump configuration, then exit" << std::endl;
                std::cout << "\t-t - start in testing mode" << std::endl;
                std::cout << "\t-u - update configuration in database" << std::endl;
                std::cout << "\t-v - possible levels are: OFF, FATAL, ERROR, WARNING, INFO, 0..9" << std::endl;
                abort();
        }
    }

}
