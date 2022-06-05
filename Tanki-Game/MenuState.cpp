#include "MenuState.h"

// Constructors & destructors
MenuState::MenuState(): State()
{
	PLOG_INFO << "Initialising main menu state";
	std::string bg_path = BASE_DIR + "bg.png";
	

	SDL_Surface* surf = IMG_Load(bg_path.c_str());
	m_bg_texture = SDL_CreateTextureFromSurface(GAME->GetRenderer(), surf);
	PLOG_INFO << "Main menu initialised";
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