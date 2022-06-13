#pragma once
#include <algorithm>
#include <sdl.h>

#include "Config.hpp"

namespace cfg
{
	class Gfx : public Config
	{
	private:
		Uint64 m_frame_time;

	public:
		Gfx();
		~Gfx() = default;

		// Window
		int window_w() const;
		int window_h() const;
		Uint32 window_flags() const;
		Uint32 render_flags() const;

		int fps_max() const;
		const Uint64& frame_time() const { return m_frame_time; };
	};
} // namespace cfg
