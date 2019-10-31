#include <iostream>
#include "executor.h"


int main (int argc, char* argv[]) {
    testtask::Options opts;

    try {
       opts.build(argc, argv);
    }
    catch (const boost::program_options::error & err) {
        std::cerr << err.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    try {    
        auto exec = std::make_unique<testtask::Executor>();
        exec->run(opts);
    }
    catch (const std::exception &err) {
        std::cerr << err.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}