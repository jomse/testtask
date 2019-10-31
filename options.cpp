#include <iostream>
#include "options.h"


namespace testtask {

namespace po = boost::program_options;

void Options::build(int argc, char** argv) {

    po::options_description desc("Options");
    desc.add_options()
        ("help,h", " print help")
        ("file,f", po::value<std::string>(&fileName_), " input file name")
        ("mode,m", po::value<std::string>(&mode_) -> value_name("[words/checksum]")," operation mode")
    ;
    po::options_description words_mode_desc("Words mode options");
    words_mode_desc.add_options()
        ("word,v", po::value<std::string>(), " search word")
    ;   

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).allow_unregistered().run(), vm);
    po::notify(vm); 
    
    if (vm.count("help")) {
        desc.add(words_mode_desc);
        std::cout << desc << std::endl;
        exit(0);
    }
    if(!vm.count("file")) {
        throw po::error("Input file name must be specified");
    }
    if(!vm.count("mode")) {
        throw po::error("Operation mode must be specified");
    }

    if (mode_ == "words") {
        desc.add(words_mode_desc);
        po::store(po::parse_command_line(argc, argv, desc), vm);
        words_mode(vm);
    }
    else if (mode_ == "checksum") {
        checksum_mode(vm);
    }
    else {
        std::cout << "Incorrect mode" << std::endl;
        exit(0);   
    } 
}

void Options::words_mode(const po::variables_map& vm) {
    if(!vm.count("word")) {
        throw po::error("Thr search word must be set");
    }
    word_ = vm["word"].as<std::string>();
}

void Options::checksum_mode(const po::variables_map& vm) {
    word_ = "";
}

const std::string& Options::fileName() const {
        return fileName_;
}

const std::string& Options::mode() const {
        return mode_;
}

const std::string& Options::word() const {
        return word_;
}
}