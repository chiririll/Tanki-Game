#include "sound.h"

cfg::Sound::Sound(): 
	// Volume
	m_main_volume(MIX_MAX_VOLUME, 0, MIX_MAX_VOLUME),
	m_sound_volume(MIX_MAX_VOLUME, 0, MIX_MAX_VOLUME),
	m_music_volume(MIX_MAX_VOLUME, 0, MIX_MAX_VOLUME),
	// Mute
	m_mute_music_focus(true),
	m_mute_sound_focus(false),
	// Base class
	Config("sound")
{
	// Volume
	InitValue("/main_volume", (ConfigValue<int>*)&m_main_volume);
	InitValue("/sound_volume", (ConfigValue<int>*) & m_sound_volume);
	InitValue("/music_volume", (ConfigValue<int>*) & m_music_volume);

	// Mute
	InitValue("/mute_sound", (ConfigValue<int>*) & m_mute_sound_focus);
	InitValue("/mute_music", (ConfigValue<int>*) & m_mute_music_focus);
}


// Getters
int cfg::Sound::GetMainVolume() const
{
	return m_main_volume.Get();
}

int cfg::Sound::GetSoundVolume() const
{
	return m_sound_volume.Get();
}

int cfg::Sound::GetMusicVolume() const
{
	return m_music_volume.Get();
}

bool cfg::Sound::MuteSoundFocus() const
{
	return m_mute_sound_focus.Get();
}

bool cfg::Sound::MuteMusicFocus() const
{
	return m_mute_music_focus.Get();
}
