#pragma once

#include <vector>
#include <string>
#include <stdexcept>

#include "GameObject.h"
#include "Map.h"
#include "HUD.h"

class State
{
private:
	std::vector<GameObject*> m_game_objects;
	uint16_t m_start_search = 0;
	
	Map m_map;
	HUD m_hud;

	// Disabling copying
	State(const State&) = delete;
	State& operator=(const State&) = delete;

protected:
	// Game objects
	void addGameObject(GameObject* object, uint16_t id);
	uint16_t addGameObject(GameObject* object);
	GameObject* getGameObject(uint16_t id);
	void deleteGameObject(uint16_t id);

public:
	// Constructors and destructors
	State();
	virtual ~State();

	// Updaters
	virtual void Update() = 0;
	virtual void FixedUpdate() = 0;
	virtual void Render() = 0;
	virtual void DrawUI() = 0;
};

