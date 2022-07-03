#include "TestState.h"

// Constructors & destructors
TestState::TestState() : State()
{
	PLOG_INFO << "Initialising test state";
}

TestState::~TestState() {
	for (auto sprite : m_sprites)
		delete sprite;

	SDL_DestroyTexture(m_bg_texture);
	Mix_FreeMusic(m_music);
}

// Start
bool TestState::Start()
{
	// Loading settings
	loadSettings("TestState");

	// Loading background image 
	m_bg_texture = m_assets->GetTexture(m_settings.value("/background"_json_pointer, ""));

	// Loading music
	m_music = m_assets->GetMusic(m_settings.value("/music"_json_pointer, ""));

	// Loading sprites
	if (m_settings.contains("/sprites"_json_pointer) && m_settings.at("/sprites"_json_pointer).type_name() == "array")
	for (auto& sprite_cfg : m_settings.at("/sprites"_json_pointer)) {
		// Skipping invalid json
		if (sprite_cfg.type_name() != "object")
			continue;
		
		m_sprites.push_back(new Sprite(sprite_cfg));
	}

	Mix_PlayMusic(m_music, -1);
	return true;
}


// Updaters
void TestState::Update(const double& delta_time)
{
	for (auto sprite : m_sprites)
		sprite->Update(delta_time);
}

void TestState::FixedUpdate()
{

}

void TestState::Render()
{
	// Displaying background
	SDL_RenderCopy(GAME->GetRenderer(), m_bg_texture, nullptr, nullptr);
	
	// And sprites
	for (auto sprite : m_sprites)
		sprite->Render();
}

void TestState::DrawUI()
{

}

void TestState::HandleEvent(SDL_Event e)
{
	if (e.type == SDL_KEYUP && e.key.keysym.sym == SDL_KeyCode::SDLK_F5)
		GAME->PushState(new TestState());
}
