#pragma once
#include <sdl.h>

#include "Config.h"

namespace cfg
{
	class Gfx : public Config
	{
	public:
		Gfx();
		~Gfx() = default;
		
		// Window
		int window_w() const;
		int window_h() const;
		Uint32 window_flags() const;

		int fps_max() const;
	};
}
