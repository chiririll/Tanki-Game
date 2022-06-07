#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "Game.h"
#include "State.h"

class MenuState : public State
{
private:
	SDL_Texture* m_bg_texture;
	Mix_Music* m_music;
	// SDL_Rect m_bg_rect;

protected:

public:
	// Constructors and destructors
	MenuState();
	virtual ~MenuState();

	// Start
	void Start() override;

	// Updaters
	void Update() override;
	void FixedUpdate() override;
	void Render() override;
	void DrawUI() override;
};
