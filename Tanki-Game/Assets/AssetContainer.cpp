#include "AssetContainer.h"

bool AssetContainer::fail()
{
    return !valid;
}

/* File reader
// Creating filestream and removing flags
std::ifstream file(m_base_path / fs::path(name));
file.unsetf(std::ios::skipws);

// If error
if (file.fail())
return nullptr;

// Conting file size
std::streampos filesize;
file.seekg(0, std::ios::end);
filesize = file.tellg();
file.seekg(0, std::ios::beg);

// Reading file
auto* data = new std::vector<char>(filesize);
file.read(reinterpret_cast<char*>(data->data()), filesize);

// Removing null bytes at the end
data->resize(file.gcount());

// */