#include "fs.hh"

size_t FS::File::GetSize(std::string path) {
	return std::filesystem::file_size(std::filesystem::path{path});
}

bool FS::File::Exists(std::string path) {
	std::ifstream fhnd(path);

	return fhnd.good();
}

std::vector <uint8_t> FS::File::Binary::Read(std::string path) {
	std::vector <uint8_t> ret;
	std::ifstream         fhnd(path, std::ios::in | std::ios::binary);
	size_t                size = FS::File::GetSize(path);

	ret.resize(size);
	fhnd.read((char*) ret.data(), size);

	return ret;
}