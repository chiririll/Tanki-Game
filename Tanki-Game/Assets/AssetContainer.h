#pragma once
#include <string>

#include <plog/Log.h>
#include <SDL.h>

using std::string;

class AssetContainer
{
private:

protected:
	bool valid;

public:
	// Con & destr
	AssetContainer(): valid(true) {};
	virtual ~AssetContainer() = default;
	
	// Status
	bool fail();

	// Assets operations
	virtual SDL_RWops* GetAsset(const string& name) = 0;
	virtual bool HasAsset(const string& name) = 0;
};

