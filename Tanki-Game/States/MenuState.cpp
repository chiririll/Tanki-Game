#include "MenuState.h"

// Constructors & destructors
MenuState::MenuState() : State()
{
	PLOG_INFO << "Initialising main menu state";
}

MenuState::~MenuState() {
	SDL_DestroyTexture(m_bg_texture);
	Mix_FreeMusic(m_music);
}


// Start
bool MenuState::Start()
{	
	// Loading state settings
	loadSettings("MainMenu");

	// Loading background 
	m_bg_texture = m_assets->GetTexture(m_settings.value("/background_image"_json_pointer, ""));

	// Loading music
	m_music = m_assets->GetMusic(m_settings.value("/music/file"_json_pointer, ""));
	int loops = m_settings.value("/music/loops"_json_pointer, -1);

	Mix_PlayMusic(m_music, loops);
	return true;
}


// Updaters
void MenuState::Update()
{
	if (++m_counter > 20000)
		GAME->PushState(new GameState());
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
