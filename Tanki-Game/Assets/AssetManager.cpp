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

void AssetManager::SetRenderer(SDL_Renderer* renderer)
{
    m_renderer = renderer;
}


// Containers
void AssetManager::AddContainer(AssetContainer* container)
{
    if (container != nullptr && !container->fail())
        m_containers.push_back(container);
}

void AssetManager::ClearContainers()
{
    for (auto container : m_containers)
        delete container;
    m_containers.erase(m_containers.begin(), m_containers.end());
}


// Assets
SDL_RWops* AssetManager::findAsset(const string& name) const
{
    for (auto container : m_containers)
        if (container->HasAsset(name))
            return container->GetAsset(name);

    return nullptr;
}

SDL_Texture* AssetManager::GetTexture(const string& name) const
{
    SDL_RWops* texture_data = findAsset("textures/" + name);
    if (texture_data == nullptr)
        // TODO: load default texture
        return nullptr;
    
    // True means that function will clean RWops
    return IMG_LoadTexture_RW(m_renderer, texture_data, true);
}

Mix_Music* AssetManager::GetMusic(const string& name) const
{
    SDL_RWops* music_data = findAsset("Music/" + name);
    
    if (music_data == nullptr)
        return nullptr;
    
    return Mix_LoadMUS_RW(music_data, true);
}

Mix_Chunk* AssetManager::GetSound(const string& name) const
{
    SDL_RWops* sound_data = findAsset("Sounds/" + name);

    if (sound_data == nullptr)
        return nullptr;

    return Mix_LoadWAV_RW(sound_data, true);
}

Map* AssetManager::GetMap(const string& name) const
{
    // TODO
    return nullptr;
}

// Default generators
SDL_Texture* AssetManager::generateMissingTexture() const
{
    // TODO
    return nullptr;
}

Mix_Music* AssetManager::generateMissingMusic() const
{
    // TODO
    return nullptr;
}

Mix_Chunk* AssetManager::generateMissingSound() const
{
    // TODO
    return nullptr;
}
