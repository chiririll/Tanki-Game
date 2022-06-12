#pragma once
#include <string>
#include <filesystem>
#include <fstream>

#include <SDL.h>

#include "../Tanki-Game.hh"
#include "AssetContainer.h"

namespace fs = std::filesystem;
using std::string;

class FolderContainer : public AssetContainer
{
private:
	fs::path m_base_path;

protected:

public:
	// Con & destr
	FolderContainer() : FolderContainer(BASE_DIR / "assets") {};
	FolderContainer(fs::path path);
	virtual ~FolderContainer() = default;
	
	// Assets
	SDL_RWops* GetAsset(const string& name);
	bool HasAsset(const string& name);
};

