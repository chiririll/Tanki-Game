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
void MenuState::Start()
{
	// using _jp = _json_pointer;

	m_data = m_assets->GetJson("GameModes/MainMenu/MainMenu.json");
	int loops = -1;
	
	try {
		// Loading background 
		m_bg_texture = m_assets->GetTexture(m_data.value("/background_image"_json_pointer, ""));

		// Loading music
		m_music = m_assets->GetMusic(m_data.value("/music/file"_json_pointer, ""));
		loops = m_data.value("/music/loops"_json_pointer, -1);
	} catch (json::exception e) {
		PLOG_ERROR << "Cannot load menu state settings: " << e.what();
		return;
	}

	Mix_PlayMusic(m_music, loops);
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
