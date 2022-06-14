#pragma once
#include <SDL_mixer.h>

#include "Config.hpp"

namespace cfg 
{
	class Sound : public Config
	{
	private:
		// Default sound settings
		BoundedValue<int> m_main_volume;
		BoundedValue<int> m_sound_volume;
		BoundedValue<int> m_music_volume;

		// Mute on focus lost
		ConfigValue<bool> m_mute_sound_focus;
		ConfigValue<bool> m_mute_music_focus;


	public:
		Sound();
		~Sound() = default;

		// Getters
		int GetMainVolume() const;
		int GetSoundVolume() const;
		int GetMusicVolume() const;

		bool MuteSoundFocus() const;
		bool MuteMusicFocus() const;

		// Setters
		// TODO
	};
} // namespace cfg
