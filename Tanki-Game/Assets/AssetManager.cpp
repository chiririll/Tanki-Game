#include "AssetManager.h"


// Con & destr
AssetManager::AssetManager() :
    m_renderer(nullptr),
    m_missing_texture(nullptr)
{}

AssetManager::~AssetManager() 
{
    SDL_DestroyTexture(m_missing_texture);
    
    ClearContainers();
}

void AssetManager::SetRenderer(SDL_Renderer* renderer)
{
    m_renderer = renderer;

    m_missing_texture = generateMissingTexture(256, 256, 16);
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
        return m_missing_texture;
    
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
SDL_Texture* AssetManager::generateMissingTexture(uint16_t w, uint16_t h, uint16_t square) const
{
    const uint8_t color_1 = 0xE3; // Magenta
    const uint8_t color_2 = 0x00; // Black

    // Creating texture
    SDL_Texture* missing = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGB332, SDL_TEXTUREACCESS_STREAMING, w, h);

    uint8_t* bitmap;
    int pitch;

    // Receiving bitmap
    SDL_LockTexture(missing, nullptr, (void**)&bitmap, &pitch);
    
    // Generating textire
    for (int y = 0; y < h; y++)
        for (int x = 0; x < pitch; x++)
            if (y % (square * 2) > 15)
                bitmap[y * pitch + x] = x % (square * 2) > 15 ? color_1 : color_2;
            else
                bitmap[y * pitch + x] = x % (square * 2) > 15 ? color_2 : color_1;

    // Saving texture
    SDL_UnlockTexture(missing);

    return missing;
}
