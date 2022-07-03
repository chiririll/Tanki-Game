#include "Sprite.h"


Sprite::Sprite(): m_texture(nullptr), m_box()
{
	// Screen size
	SDL_GetWindowSize(GAME->GetWindow(), &m_screen_w, &m_screen_h);
}

Sprite::Sprite(SDL_Texture* texture) : m_texture(texture), m_box()
{
	initTexture();
}

Sprite::Sprite(const json& sprite): Sprite()
{
	// Creating sprite
	m_texture = GAME->GetAssetManager()->GetTexture(sprite.value("/texture"_json_pointer, ""));
	initTexture();

	SetScale(sprite.value("/scale"_json_pointer, 1.0f));

	SetSpeed(
		sprite.value("/speed/horizontal"_json_pointer, 0.0f),
		sprite.value("/speed/vertical"_json_pointer, 0.0f),
		sprite.value("/speed/rotation"_json_pointer, 0.0f)
	);
	SetPosition(
		sprite.value("/pos/x"_json_pointer, 0),
		sprite.value("/pos/y"_json_pointer, 0)
	);
}

Sprite::~Sprite()
{
	if (m_texture != nullptr)
		SDL_DestroyTexture(m_texture);
}

void Sprite::initTexture()
{
	if (m_texture == nullptr)
		return;

	// Receiving texture sizes
	SDL_QueryTexture(m_texture, nullptr, nullptr, &m_box.w, &m_box.h);
}

void Sprite::bounce(double& axis, const int& screen_size, const int& size, double& speed, bool& flip_axis)
{
	if (speed == 0)
		return;

	if (axis + size > screen_size) 
		axis = screen_size - size;
	else if (axis < 0) 
		axis = 0;
	else 
		return;

	flip_axis = !flip_axis;
	speed = -speed;
}

void Sprite::SetPosition(int x, int y)
{
	m_x = x;
	m_box.x = x;

	m_y = y;
	m_box.y = y;
}

void Sprite::SetScale(double scale)
{
	m_box.w = (int)((double)m_box.w * scale);
	m_box.h = (int)((double)m_box.h * scale);
}

void Sprite::SetSpeed(double horizontal, double vertical, double rotation)
{
	m_horiz_speed = horizontal;
	m_vert_speed = vertical;
	m_rotation_speed = rotation;
}

void Sprite::Update(double dt) {
	// Rotating
	m_angle += m_rotation_speed * dt;

	// Bounding angle
	if (m_angle >= 360 || m_angle <= -360) m_angle = 0;

	// Moving 
	m_x += m_horiz_speed * dt;
	m_y += m_vert_speed * dt;

	// Bounding x
	bounce(m_x, m_screen_w, m_box.w, m_horiz_speed, m_flip.horizontally);
	/*if (m_x > m_screen_w) m_x = 0;
	if (m_x < 0) m_x = m_screen_w;*/


	// Bounding y
	bounce(m_y, m_screen_h, m_box.h, m_vert_speed, m_flip.vertically);
	/*if (m_y > m_screen_h) m_y = 0;
	if (m_y < 0) m_y = m_screen_h;*/

	// Applying move
	m_box.x = (int)m_x;
	m_box.y = (int)m_y;
}

void Sprite::Render()
{
	SDL_RenderCopyEx(GAME->GetRenderer(), m_texture, nullptr, &m_box, m_angle, nullptr, m_flip.toSDL());
}
