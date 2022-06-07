#include "AssetManager.h"


// Con & destr
AssetManager::AssetManager()
{
    m_missing_texture = generateMissingTexture();
    m_missing_music = generateMissingMusic();
    m_missing_sound = generateMissingSound();
}

AssetManager::~AssetManager() 
{
    SDL_DestroyTexture(m_missing_texture);
    Mix_FreeMusic(m_missing_music);
    Mix_FreeChunk(m_missing_sound);
    
    ClearContainers();
}


// Containers
void AssetManager::AddContainer(AssetContainer* container)
{
    if (container != nullptr && container->isValid())
        m_containers.push_back(container);
}

void AssetManager::ClearContainers()
{
    for (auto container : m_containers)
        delete container;
    m_containers.erase(m_containers.begin(), m_containers.end());
}


// Assets
Asset* AssetManager::findAsset(const string& name)
{
    for (auto container : m_containers)
        if (container->HasAsset(name))
            return container->GetAsset(name);
    return nullptr;
}

SDL_Texture* AssetManager::GetTexture(const string& name)
{
    // TODO
    return nullptr;
}

Mix_Music* AssetManager::GetMusic(const string& name)
{
    // TODO
    return nullptr;
}

Mix_Chunk* AssetManager::GetSound(const string& name)
{
    // TODO
    return nullptr;
}

Map* AssetManager::GetMap(const string& name)
{
    // TODO
    return nullptr;
}

// Default generators
SDL_Texture* AssetManager::generateMissingTexture()
{
    // TODO
    return nullptr;
}

Mix_Music* AssetManager::generateMissingMusic()
{
    // TODO
    return nullptr;
}

Mix_Chunk* AssetManager::generateMissingSound()
{
    // TODO
    return nullptr;
}
