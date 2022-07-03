#include "SplashState.h"


// Constructors & destructors
SplashState::SplashState() : State()
{
	PLOG_INFO << "Initialising splash state";
}

SplashState::~SplashState() {
	SDL_DestroyTexture(m_splash_texture);
	Mix_FreeMusic(m_intro_music);
}


// Start
bool SplashState::Start()
{
	// Loading background 
	m_splash_texture = m_assets->GetTexture("backgrounds/splash.png");

	// Loading music
	m_intro_music = m_assets->GetMusic("intro.mp3");
	
	Mix_PlayMusic(m_intro_music, 1);
	return true;
}


// Updaters
void SplashState::Update(const double& dt)
{
	// Fade effect
	m_alpha += FADE_SPEED * dt;
	if (m_alpha > 255)
		GAME->PushState(new MenuState());
}

void SplashState::Render()
{
	// Rendering texture
	SDL_SetTextureAlphaMod(m_splash_texture, (Uint8)std::floor(m_alpha));
	SDL_RenderCopy(GAME->GetRenderer(), m_splash_texture, nullptr, nullptr);
}
