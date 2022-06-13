#include "GameState.h"

GameState::~GameState() {
	delete m_map;

	Mix_FreeMusic(m_music);
}

// Constructors & destructors
GameState::GameState() : State()
{
	PLOG_INFO << "Initialising game state";
}


// Start
bool GameState::Start()
{
	// Loading state settings
	loadSettings("Survival");

	// Loading map 
	m_map = m_assets->GetMap(m_settings["/map"_json_pointer]);
	if (m_map == nullptr)
		return false;

	// Loading music
	m_music = m_assets->GetMusic("brainloop.mp3");

	Mix_PlayMusic(m_music, -1);

	return true;
}


// Updaters
void GameState::Update()
{

}

void GameState::FixedUpdate()
{

}

void GameState::Render()
{
	if (++count > 50000)
		GAME->PushState(new MenuState());
}

void GameState::DrawUI()
{

}
