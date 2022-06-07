#pragma once
#include <string>
#include <sdl.h>
#include <sdl_mixer.h>
#include <nlohmann/json.hpp>

#include "AssetContainer.h"
#include "../Map.h"

using std::string;
using std::vector;

class AssetManager
{
private:
	// Variables
	vector<AssetContainer*> m_containers;
	// Default assets
	SDL_Texture* m_missing_texture;
	Mix_Music* m_missing_music;
	Mix_Chunk* m_missing_sound;

	// Methods
	Asset* findAsset(const string& name);

	// Default generators
	SDL_Texture* generateMissingTexture();
	Mix_Music* generateMissingMusic();
	Mix_Chunk* generateMissingSound();

	// Disabling copying
	AssetManager(const AssetManager&) = delete;
	AssetManager& operator=(const AssetManager&) = delete;

public:
	// Con & destr
	AssetManager();
	virtual ~AssetManager();

	// Containers
	void AddContainer(AssetContainer* container);
	void ClearContainers();

	// Assets
	SDL_Texture* GetTexture(const string& name);
	Mix_Music* GetMusic(const string& name);
	Mix_Chunk* GetSound(const string& name);
	Map* GetMap(const string& name);
};
