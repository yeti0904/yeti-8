#ifndef YETI8_FS_HH
#define YETI8_FS_HH

#include "_components.hh"

namespace FS {
	namespace File {
		size_t GetSize(std::string path);
		bool   Exists(std::string path);
		namespace Binary {
			std::vector <uint8_t> Read(std::string path);
		}
	}
}

#endif