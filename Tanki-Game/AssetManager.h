#pragma once
#include <sdl.h>
#include <nlohmann/json.hpp>

#include "Map.h"

class AssetManager
{
private:
	
protected:

public:
	AssetManager();
	virtual ~AssetManager() = default;

	SDL_Texture* GetTexture();
	Map* GetMap();
};
