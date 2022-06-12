#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "../Game.h"
#include "State.h"
#include "GameState.h"

using nlohmann::json;

class MenuState : public State
{
private:
	// Settings
	json m_data;

	// Multimedia
	SDL_Texture* m_bg_texture;
	Mix_Music* m_music;

	// FIXME
	int m_counter = 0;

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