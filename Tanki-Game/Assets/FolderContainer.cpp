#include "FolderContainer.h"

// Con & destr
FolderContainer::FolderContainer(fs::path path) : m_base_path(path)
{
	// Checking if folder exists
	if (!fs::exists(m_base_path)) {
		PLOG_ERROR << "Cant load assets folder '" + m_base_path.string() + "' cause it doesn't exists!";
		valid = false;
	}
}

// Assets
SDL_RWops* FolderContainer::GetAsset(const string& name)
{
	if (!HasAsset(name))
		return nullptr;

	// Reading asset
	SDL_RWops* data = SDL_RWFromFile(
		(m_base_path / fs::path(name)).string().c_str(), 
		"rb"
	);

	return data;
}

bool FolderContainer::HasAsset(const string& name)
{
	return fs::exists(m_base_path / fs::path(name));
}
