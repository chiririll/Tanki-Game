#pragma once
#include <nlohmann/json.hpp>

#include "../Game.h"

struct Flip
{
	bool horizontally = false;
	bool vertically = false;

	SDL_RendererFlip toSDL() { return (SDL_RendererFlip(((int)vertically * 2) | (int)horizontally)); }
};

// Simple type of GameObject 
// because not enough time (and mostly motivation) to implement component system
// howewer, the goal is getting closer and closer 
// it's just crazy to repeat the same code and it made me write this class
class Sprite
{
private:
	SDL_Texture* m_texture;
	SDL_Rect m_box;

	// Screen size
	int m_screen_w = 0, m_screen_h = 0;

	// Position and rotation
	double m_angle = 0;
	double m_x = 0, m_y = 0;
	
	// Flip verticallt and horizontaly
	Flip m_flip;

	// Speed 
	double m_rotation_speed = 0;
	double m_vert_speed = 0, m_horiz_speed = 0;

	// Initializers
	void initTexture();

	// Physics (very simple)
	void bounce(double& axis, const int& screen_size, const int& size, double& speed, bool& flip_axis);

public:
	// Con & dest
	Sprite();
	Sprite(SDL_Texture* texture);
	Sprite(const json& sprite);

	Sprite(const Sprite&) = delete;
	Sprite& operator=(const Sprite&) = delete;
	~Sprite();

	// Setters
	void SetPosition(int x, int y);
	void SetScale(double scale);
	void SetSpeed(double horizontal, double vertical, double rotation);

	// Update
	void Update(double dt);
	void Render();
};
