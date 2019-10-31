#pragma once
#include <fstream>
#include <string>


namespace testtask {

class FileOperation {
private:
    std::string buildStr(const std::string::iterator& it_begin, const std::string::iterator& it);
public:
    unsigned int countChecksum(std::istream& stream);
    unsigned int countWord(std::istream& stream, const std::string& word);
};
}