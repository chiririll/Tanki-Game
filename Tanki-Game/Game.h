#pragma once
// C++ libs
#include <string>
#include <map>
#include <filesystem>

namespace fs = std::filesystem;

// External libs
#include <SDL.h>

// Logger
#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>
#include <plog/Appenders/ColorConsoleAppender.h>

// Properties
#include "Tanki-Game.hh"

// States
#include "State.h"

// Configs
#include "Configs/Gfx.h"

// Assets
#include "Assets/AssetManager.h"


#define GAME Game::GetInstance()


class Game
{
private:
    // Singleton
    static Game* pinstance_;

    // Variables 
    SDL_Window* m_main_window;
    SDL_Renderer* m_main_renderer;
    State* m_state;

    // Configs
    cfg::Gfx m_gfx_conf;

    // Assets
    AssetManager m_assets;

    // Delta time
    Uint64 dt_last;
    double deltaTime;

    // Initialization 
    void initMainWindow();
    void initMainRenderer();
    void initAssets();
    void initAudio();
    void initFolders();

    // Updaters 
    void updateEvents();
    void updateDt();
    void update();
    void render();
    void drawUI();

protected:
    Game();
    Game(Game&) = delete;
    void operator=(const Game&) = delete;
    ~Game();

public:
    // Start and stop
    void Run();
    void Stop();

    // States
    void PushState(State* = nullptr);

    // Singleton
    static Game* GetInstance();

    // Getters
    double get_dt() { return deltaTime; }
    SDL_Renderer* GetRenderer() { return m_main_renderer; }
    const AssetManager* GetAssetManager() { return &m_assets; }
};
