#include "AssetManager.h"


// Con & destr
AssetManager::AssetManager() :
    m_renderer(nullptr)
{}

AssetManager::~AssetManager() 
{
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


// Utils
void AssetManager::RWops2string(SDL_RWops* file, string& str, bool freesrc) const
{
    // Counting size
    size_t size = SDL_RWsize(file);

    // Creating string
    str.clear();
    str.resize(size);
    
    // Reading file
    SDL_RWseek(file, 0, RW_SEEK_SET);
    SDL_RWread(file, str.data(), 1, size);

    // Cleaning memory
    if (freesrc)
        SDL_RWclose(file);
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
        return generateMissingTexture(256, 256, 16);
    
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

bool AssetManager::GetTileset(tmx::Tileset& tileset, tmx::Map* map) const
{
    SDL_RWops* tsx_file = findAsset(tileset.getSource());

    if (tsx_file == nullptr)
        return false;

    string tsx_string;
    RWops2string(tsx_file, tsx_string, true);

    return tileset.parse_string(tsx_string, map);
}

Map* AssetManager::GetMap(const string& name) const
{
    SDL_RWops* map_file = findAsset("Maps/" + name + "/" + name + ".tmx");

    if (map_file == nullptr) {
        PLOG_WARNING << "Can't load map '" + name + "': file doesn't exists";
        return nullptr;
    }
        

    // Loading string
    string map_str;
    RWops2string(map_file, map_str, true);
    
    // Loading map data from string
    tmx::Map map_data;
    if (!map_data.loadFromString(map_str, "")) {
        PLOG_WARNING << "Can't load map '" + name + "': parsing error";
        return nullptr;
    }

    // Loading tilemaps
    for (auto& tileset : map_data.getTilesets_m()) {
        GetTileset(tileset, &map_data);
    }

    // Creting map
    Map* map = new Map(std::move(map_data));

    return map;
}

json AssetManager::GetJson(const string& name) const
{
    SDL_RWops* j_file = findAsset(name);
    
    // File doesn't exists
    if (j_file == nullptr) {
        PLOG_WARNING << "Json file '" + name + "' doesn't exists";
        return json::parse("{}");
    }
    
    // Reading into string
    string j_string;
    RWops2string(j_file, j_string, true);

    // Creating json
    try {
        return json::parse(j_string);
    } catch (json::parse_error e) {
        PLOG_ERROR << "Cant parse json file '" + name + "': " + e.what();
    }

    return json::parse("{}");
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
