#pragma once

#include <vector>
#include <string>
#include <stdexcept>

#include "../GameObject.h"
#include "../Assets/AssetManager.h"
#include "../Map/Map.h"
#include "../HUD/HUD.h"

class State
{
private:
	std::vector<GameObject*> m_game_objects;
	uint16_t m_start_search = 0;
	
	// Map m_map;
	HUD m_hud;

	// Disabling copying
	State(const State&) = delete;
	State& operator=(const State&) = delete;

protected:
	// Variables
	json m_settings;
	string m_error;

	// Asset Manager
	const AssetManager* m_assets;

	// Settings
	void loadSettings(const string& state_name);

	// Game objects
	void addGameObject(GameObject* object, uint16_t id);
	uint16_t addGameObject(GameObject* object);
	GameObject* getGameObject(uint16_t id);
	void deleteGameObject(uint16_t id);

public:
	// Constructors and destructors
	State(): State(nullptr) {};
	State(const AssetManager* asset_manager);
	virtual ~State();

	// Errors
	string GetError() { return m_error; }

	// Variables
	void AddAssetManager(const AssetManager* manager);

	// Start
	virtual bool Start() = 0;

	// Updaters
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
	virtual void Render() = 0;
	virtual void DrawUI() = 0;
};

