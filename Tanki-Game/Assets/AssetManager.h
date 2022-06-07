#pragma once
#include <string>
#include <sdl.h>
#include <SDL_image.h>
#include <sdl_mixer.h>
#include <nlohmann/json.hpp>

#include "../Tanki-Game.hh"
#include "AssetContainer.h"
#include "../Map.h"

using std::string;
using std::vector;

class AssetManager
{
private:
	// Variables
	vector<AssetContainer*> m_containers;
	SDL_Renderer* m_renderer;

	// Default assets
	SDL_Texture* m_missing_texture;
	Mix_Music* m_missing_music;
	Mix_Chunk* m_missing_sound;

	// Methods
	Asset* findAsset(const string& name) const;

	// Default generators
	SDL_Texture* generateMissingTexture() const;
	Mix_Music* generateMissingMusic() const;
	Mix_Chunk* generateMissingSound() const;

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
	Map* GetMap(const string& name) const;
};
