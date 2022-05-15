#pragma once

#include <vector>

#include "GameObject.h"
#include "Map.h"
#include "HUD.h"

class State
{
private:
	std::vector<GameObject*> m_game_objects;
	Map m_map;
	HUD m_hud;

public:
	virtual void Start() {};
	virtual void Update() {};
	virtual void FixedUpdate() {};
	virtual void Render() {};
};

