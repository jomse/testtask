#include <memory>
#include "executor.h"


namespace testtask {

void Executor::run (const Options& opts) { 
	std::ifstream file;
	FileOperation exec;
	if (opts.mode() == "checksum") {
		file.open(opts.fileName().c_str(), std::ifstream::binary);
		if (file.fail()) {
			throw std::runtime_error("Can`t open file");
		}
		std::cout << exec.countChecksum(file) << std::endl;
	}
	else {
		file.open(opts.fileName().c_str(), std::fstream::in);
		if (file.fail()) {
			throw std::runtime_error("Can`t open file");
		}
		std::cout << exec.countWord(file, opts.word()) << std::endl;
	}
	file.close();
}
}