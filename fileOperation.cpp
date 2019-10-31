#include <arpa/inet.h>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "fileOperation.h"


namespace testtask {

unsigned int FileOperation::countChecksum (std::istream& stream) {
	uint32_t checksum = 0, buff;
	while (stream.good()) {
		buff = 0;
		stream.read(reinterpret_cast<char*>(&buff), sizeof(uint32_t));
		checksum += htonl(buff);
	}
	return (unsigned int)checksum;
}

unsigned int FileOperation::countWord(std::istream& stream, const std::string& word) {
	unsigned int count = 0;
	std::string line = "";
	
	while (std::getline(stream, line)) {    //doesn`t work with lines longer than string::size_type
	   	auto it_begin = line.begin();
       	while (it_begin != line.end() ) {
       		auto it = std::find_if(it_begin+1, line.end(),
			[] (const char element) -> bool {return std::isspace(element) || std::ispunct(element);});
			
			if (buildStr(it_begin+1, it) == word) {
				count++;
			}
			it_begin = it;
		}
	}
	return count;
}

std::string FileOperation::buildStr (const std::string::iterator& it_begin, const std::string::iterator& it) {
	std::string returnedStr = "";
	auto begin = it_begin;
	while (begin != it) {
		returnedStr += *begin;
		begin++;
	}
	return returnedStr;
}
}