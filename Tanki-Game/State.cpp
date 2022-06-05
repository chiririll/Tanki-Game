#include "State.h"

// Constructors and destructors
State::State()
{

}

State::~State()
{

}

// Game Objects
void State::addGameObject(GameObject* object, uint16_t id = 0)
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

uint16_t State::addGameObject(GameObject* object)
{
	for (uint16_t i = m_start_search; i < m_game_objects.size(); i++)
		if (m_game_objects[i] == nullptr) {
			m_game_objects[i] = object;
			m_start_search = i + 1;
			return i;
		}
	
	m_game_objects.push_back(object);
	m_start_search = m_game_objects.size();
	return m_game_objects.size() - 1;
}

GameObject* State::getGameObject(uint16_t id)
{
	if (m_game_objects.size() > id)
		return m_game_objects[id];
	return nullptr;
}

void State::deleteGameObject(uint16_t id)
{
	if (m_game_objects.size() > id && m_game_objects[id]) {
		delete m_game_objects[id];
		if (id < m_start_search)
			m_start_search = id;
	}
}
