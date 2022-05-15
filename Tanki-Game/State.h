#pragma once

#include <map>

#include "GameObject.h"
#include "Map.h"
#include "HUD.h"

class State
{
private:
	std::map<unsigned short, GameObject*> m_game_objects;
	unsigned short m_free_id = 1;
	
	// TODO: Add friend class for networking 

protected:
	Map m_map;
	HUD m_hud;

public:
	// Constructors and destructors
	State();
	virtual ~State();

	// Game Objects
	// TODO: Make accessable by server only
	int AddGameObject(GameObject* object, unsigned short id);
	GameObject* GetGameObject(unsigned short id);
	void RemoveGameObject(unsigned short id);
	void RebaseGameObjects();

	// Updaters
	virtual void Update();
	virtual void FixedUpdate();
	virtual void Render();
};

