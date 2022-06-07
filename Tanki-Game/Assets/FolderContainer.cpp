#include "FolderContainer.h"

// Con & destr
FolderContainer::FolderContainer(fs::path path) : m_base_path(path)
{
	// Checking if folder exists
	if (!fs::exists(path)) {
		PLOG_ERROR << "Cant load assets folder '" + path.string() + "' cause it doesn't exists!";
		valid = false;
	}
}

// Assets
Asset* FolderContainer::GetAsset(const string& name)
{
	if (!HasAsset(name))
		return nullptr;

	// TODO: read asset
	return nullptr;
}

bool FolderContainer::HasAsset(const string& name)
{
	return fs::exists(m_base_path / fs::path(name));
}
