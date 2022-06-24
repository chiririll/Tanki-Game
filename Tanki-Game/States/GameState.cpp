#include "GameState.h"

GameState::~GameState() {
	delete m_map;

	Mix_FreeMusic(m_music);
}

// Constructors & destructors
GameState::GameState() : State(), m_bg_texture()
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
void GameState::Update(const double& dt)
{
	count += dt;
	if (count > 10)
		GAME->PushState(new MenuState());
}

void GameState::FixedUpdate()
{

}

void GameState::Render()
{

}

void GameState::DrawUI()
{

}
