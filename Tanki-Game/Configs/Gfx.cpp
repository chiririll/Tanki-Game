#include "Gfx.h"


cfg::Gfx::Gfx(): Config("gfx")
{
	// Initialize defaults
	// Window
	setDefault("window_resolution", {1920, 1080});
	setDefault("window_mode", "windowed");

	// FPS
	setDefault("fps_max", 240);
}

// Window params
int cfg::Gfx::window_w() const
{
	return m_config["window_resolution"][0].get<int>();
}

int cfg::Gfx::window_h() const
{
	return m_config["window_resolution"][1].get<int>();
}

Uint32 cfg::Gfx::window_flags() const
{
	string mode = m_config["window_mode"].get<string>();
	
	if (mode == "fullscreen")
		return SDL_WINDOW_FULLSCREEN;
	if (mode == "borderless")
		return SDL_WINDOW_FULLSCREEN_DESKTOP;
	// windowed
	return 0;
}

int cfg::Gfx::fps_max() const
{
	return m_config["fps_max"].get<int>();
}
