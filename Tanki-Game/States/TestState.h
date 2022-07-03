#pragma once
#include <vector>

#include "State.h"
#include "../GameObjects/Sprite.h"
#include "../Game.h"

class Sprite;

class TestState : public State
{
private:
	SDL_Texture* m_bg_texture = nullptr;
	Mix_Music* m_music = nullptr;

	std::vector<Sprite*> m_sprites;
	
public:
	// Constructors and destructors
	TestState();
	virtual ~TestState();

	// Start
	bool Start() override;

	// Updaters
	void Update(const double& delta_time) override;
	void FixedUpdate() override;
	void Render() override;
	void DrawUI() override;

	// Events
	void HandleEvent(SDL_Event e) override;
};

