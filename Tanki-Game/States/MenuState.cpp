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
	m_bg_texture = m_assets->GetTexture("Backgrounds/menu.png");
	m_artem = m_assets->GetTexture("5ka.png");
	m_vital = m_assets->GetTexture("meshkoff.png");

	SDL_QueryTexture(m_artem, nullptr, nullptr, &m_artem_hitbox.w, &m_artem_hitbox.h);
	SDL_QueryTexture(m_vital, nullptr, nullptr, &m_vital_hitbox.w, &m_vital_hitbox.h);
	m_artem_hitbox.w /= 5;
	m_artem_hitbox.h /= 5;
	m_artem_hitbox.y = 410;

	m_vital_hitbox.w /= 8;
	m_vital_hitbox.h /= 8;
	m_vital_hitbox.y = 0;
	// Loading music
	m_music = m_assets->GetMusic("fingerloop.mp3");

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
	pos += 0.1;
	if (pos > 1124)
		pos = 0;
	m_artem_hitbox.x = int(pos) - 100;
	m_vital_hitbox.x = 1024 - int(pos) - 100;
	SDL_RenderCopy(GAME->GetRenderer(), m_bg_texture, nullptr, nullptr);
	
	SDL_RenderCopyEx(GAME->GetRenderer(), m_artem, nullptr, &m_artem_hitbox, 0, nullptr, SDL_FLIP_NONE);
	
	SDL_RenderCopyEx(GAME->GetRenderer(), m_vital, nullptr, &m_vital_hitbox, count, nullptr, SDL_FLIP_VERTICAL);
	
	/// SDL_RenderCopyEx(GAME->GetRenderer(), m_bg_texture, nullptr, nullptr, -count, nullptr, SDL_FLIP_NONE);
	count += .1;
	if (count >= 360)
		count = 0;
}

void MenuState::DrawUI()
{

}
