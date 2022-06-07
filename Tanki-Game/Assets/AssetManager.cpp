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
Asset* AssetManager::findAsset(const string& name) const
{
    for (auto container : m_containers)
        if (container->HasAsset(name))
            return container->GetAsset(name);
    return nullptr;
}

SDL_Texture* AssetManager::GetTexture(const string& name) const
{
    // TODO
    const fs::path bg_path = BASE_DIR / fs::path("assets/Textures/" + name);

    PLOGD << bg_path;

    SDL_Surface* surf = IMG_Load(bg_path.string().c_str());
    auto texture = SDL_CreateTextureFromSurface(m_renderer, surf);
    SDL_FreeSurface(surf);
    return texture;
}

Mix_Music* AssetManager::GetMusic(const string& name) const
{
    // TODO
    const fs::path mus_path = BASE_DIR / fs::path("assets/Music/" + name);
    PLOGD << mus_path;
    return Mix_LoadMUS(mus_path.string().c_str());
}

Mix_Chunk* AssetManager::GetSound(const string& name) const
{
    // TODO
    return nullptr;
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
