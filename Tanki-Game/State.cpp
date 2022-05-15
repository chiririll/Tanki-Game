#include "State.h"

// Constructors and destructors
State::State()
{
}

State::~State()
{
}


// Game Objects
int State::AddGameObject(GameObject* object, unsigned short id = 0)
{
	// If we want custom id and it's free
	if (!id || !m_game_objects.contains(id))
		id = m_free_id++;

	object->m_id = id;
	m_game_objects[m_free_id] = object;
	return id;
}

GameObject* State::GetGameObject(unsigned short id)
{
	if (m_game_objects.contains(id))
		return m_game_objects[id];
	return nullptr;
}

void State::RemoveGameObject(unsigned short id)
{
	if (!m_game_objects.contains(id))
		return;

	m_game_objects.erase(id);
}

void State::RebaseGameObjects()
{
	// TODO
}


// Updates
void State::Update()
{
	// TODO: Foreach GameObject call Update
}

void State::FixedUpdate()
{
	// TODO: -//-
}

void State::Render()
{
	// TODO: -//-
}
