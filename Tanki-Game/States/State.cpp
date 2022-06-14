#include "State.h"

// Constructors and destructors
State::State(const AssetManager* asset_manager) : m_assets(asset_manager), m_error("")
{

}

State::~State()
{

}

void State::AddAssetManager(const AssetManager* manager)
{
	m_assets = manager;
}

void State::loadSettings(const string& state_name)
{
	m_settings = m_assets->GetJson("GameModes/" + state_name + "/" + state_name + ".json");
}

// Game Objects
void State::addGameObject(GameObject* object, Uint32 id = 0)
{
	// If vector too short
	if (m_game_objects.size() <= id) {
		m_game_objects.resize(id + 1);
		m_game_objects[id] = object;
	}

	// If id collision
	if (m_game_objects[id] != nullptr)
		throw std::runtime_error("Object with id = " + std::to_string(id) + " already exists!");
	
	// All is ok
	m_game_objects[id] = object;
}

Uint32 State::addGameObject(GameObject* object)
{
	for (Uint32 i = m_start_search; i < m_game_objects.size(); i++)
		if (m_game_objects[i] == nullptr) {
			m_game_objects[i] = object;
			m_start_search = i + 1;
			return i;
		}
	
	m_game_objects.push_back(object);
	m_start_search = m_game_objects.size();
	return m_game_objects.size() - 1;
}

GameObject* State::getGameObject(Uint32 id)
{
	if (m_game_objects.size() > id)
		return m_game_objects[id];
	return nullptr;
}

void State::deleteGameObject(Uint32 id)
{
	if (m_game_objects.size() > id && m_game_objects[id]) {
		delete m_game_objects[id];
		if (id < m_start_search)
			m_start_search = id;
	}
}
