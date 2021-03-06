#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "../Game.h"
#include "../Map/Map.h"
#include "State.h"
#include "MenuState.h"

class GameState : public State
{
private:
	Map *m_map;

	// Multimedia
	Mix_Music* m_music;
	SDL_Texture* m_bg_texture;
	
	// FIXME
	double count = 0;

protected:

public:
	// Constructors and destructors
	GameState();
	virtual ~GameState();

	// Start
	bool Start() override;

	// Updaters
	void Update(const double& delta_time) override;
	void FixedUpdate() override;
	void Render() override;
	void DrawUI() override;
};
