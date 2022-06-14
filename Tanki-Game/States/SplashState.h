#pragma once
#include <cmath>

#include "State.h"
#include "MenuState.h"
#include "../Game.h"

class SplashState : public State
{
private:
	// Multimedia
	SDL_Texture* m_splash_texture = nullptr;
	Mix_Music* m_intro_music = nullptr;

	// Fade in effect
	double m_alpha = 1;
	const double FADE_SPEED = 128;

public:
	// Constructors and destructors
	SplashState();
	virtual ~SplashState();

	// Start
	bool Start() override;

	// Updaters
	void Update(const double& delta_time) override;
	void FixedUpdate() {};
	void Render() override;
	void DrawUI() {};

};

