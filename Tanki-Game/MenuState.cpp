#include "MenuState.h"

MenuState::~MenuState() {
	SDL_DestroyTexture(m_bg_texture);
	Mix_FreeMusic(m_music);
}

// Constructors & destructors
MenuState::MenuState(): State()
{
	PLOG_INFO << "Initialising main menu state";
}


// Start
void MenuState::Start()
{
	// Loading image 
	m_bg_texture = m_assets->GetTexture("default.png");
	// Loading music
	m_music = m_assets->GetMusic("obormot.mp3");

	Mix_PlayMusic(m_music, -1);
}


// Updaters
void MenuState::Update()
{

}

void MenuState::FixedUpdate()
{

}

void MenuState::Render()
{
	SDL_RenderCopy(GAME->GetRenderer(), m_bg_texture, nullptr, nullptr);
}

void MenuState::DrawUI()
{

}
