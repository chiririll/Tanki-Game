#include "MenuState.h"

MenuState::~MenuState() {
	SDL_DestroyTexture(m_bg_texture);
}

// Constructors & destructors
MenuState::MenuState(): State()
{
	PLOG_INFO << "Initialising main menu state";
	
	const fs::path bg_path = BASE_DIR / fs::path("bg.png");

	SDL_Surface* surf = IMG_Load(bg_path.string().c_str());
	m_bg_texture = SDL_CreateTextureFromSurface(GAME->GetRenderer(), surf);
	SDL_FreeSurface(surf);
	
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
