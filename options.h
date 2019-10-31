#pragma once 
#include <string>
#include <boost/program_options.hpp>


namespace testtask {

class Options {
private:
    std::string fileName_;
    std::string mode_;
    std::string word_;
    void words_mode(const boost::program_options::variables_map& vm);
    void checksum_mode(const boost::program_options::variables_map& vm);

public:
    void build(int argc, char** argv);
    const std::string& fileName()const;
    const std::string& mode()const;
    const std::string& word()const;

};
}