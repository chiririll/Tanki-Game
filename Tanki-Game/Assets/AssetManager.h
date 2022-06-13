#pragma once
#include <vector>
#include <string>

#include <sdl.h>
#include <SDL_image.h>
#include <sdl_mixer.h>
#include <nlohmann/json.hpp>
#include <tmxlite/Map.hpp>
#include <tmxlite/Tileset.hpp>

#include "../Tanki-Game.hh"
#include "AssetContainer.h"
#include "../Map/Map.h"

using std::string;
using nlohmann::json;

class AssetManager
{
private:
	// Variables
	std::vector<AssetContainer*> m_containers;
	SDL_Renderer* m_renderer;

	// Methods
	SDL_RWops* findAsset(const string& name) const;
	void RWops2string(SDL_RWops* file, string& str, bool freesrc = false) const;

	// Default generators
	SDL_Texture* generateMissingTexture(uint16_t w, uint16_t h, uint16_t square) const;

	// Disabling copying
	AssetManager(const AssetManager&) = delete;
	AssetManager& operator=(const AssetManager&) = delete;

public:
	// Con & destr
	AssetManager();
	virtual ~AssetManager();

	// Variables
	void SetRenderer(SDL_Renderer* renderer);

	// Containers
	void AddContainer(AssetContainer* container);
	void ClearContainers();

	// Assets
	SDL_Texture* GetTexture(const string& name) const;
	Mix_Music* GetMusic(const string& name) const;
	Mix_Chunk* GetSound(const string& name) const;
	bool GetTileset(tmx::Tileset& tileset, tmx::Map* map) const;
	Map* GetMap(const string& name) const;
	json GetJson(const string& name) const;
};
