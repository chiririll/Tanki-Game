#include "Gfx.h"


cfg::Gfx::Gfx(): Config("gfx")
{
	// Initialising defaults
	/*SetDefault("/resolution",
		{
			{"width", 720},
			{"height", 576}
		});*/
	SetDefault("/resolution/width", 925);
	SetDefault("/resolution/height", 530);
	SetDefault("/vsync", true);

	SetDefault("/window_mode", "windowed");
	SetDefault("/fps_lock", 240);
}

// Window params
int cfg::Gfx::window_w() const
{
	return GetValue<int>("/resolution/width");
}

int cfg::Gfx::window_h() const
{
	return GetValue<int>("/resolution/height");
}

Uint32 cfg::Gfx::window_flags() const
{
	string mode = GetValue<string>("/window_mode");
	
	if (mode == "fullscreen")
		return SDL_WINDOW_FULLSCREEN;
	if (mode == "borderless")
		return SDL_WINDOW_FULLSCREEN_DESKTOP;
	// windowed
	return 0;
}

Uint32 cfg::Gfx::render_flags() const
{
	// vsync
	bool vsync = GetValue<bool>("/vsync");

	if (vsync)
		return SDL_RENDERER_PRESENTVSYNC;
	
	return 0;
}

int cfg::Gfx::fps_max() const
{
	return GetValue<int>("/fps_lock");
}
