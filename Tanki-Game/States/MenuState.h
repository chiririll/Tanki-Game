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
	// Multimedia
	SDL_Texture* m_bg_texture;
	Mix_Music* m_music;

	// FIXME
	double m_counter = 0;

protected:

public:
	// Constructors and destructors
	MenuState();
	virtual ~MenuState();

	// Start
	bool Start() override;

	// Updaters
	void Update(const double& delta_time) override;
	void FixedUpdate() override;
	void Render() override;
	void DrawUI() override;
};
