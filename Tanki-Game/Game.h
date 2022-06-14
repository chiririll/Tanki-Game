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

// Configs
#include "Configs/Gfx.h"
#include "Configs/Sound.h"

// Assets
#include "Assets/AssetManager.h"
#include "Assets/FolderContainer.h"

// States
#include "States/State.h"
#include "States/MenuState.h"


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
    cfg::Sound m_sound_conf;

    // Assets
    AssetManager m_assets;

    // Initialization 
    void initMainWindow();
    void initMainRenderer();
    void initAssets();
    void initAudio();
    void initFolders();

    // Events
    void updateEvents();
    void handleWindowEvent(Uint8 window_event);

    // Updaters 
    void update(Uint64& prev_update, Uint64& next_update, double& delta_time);
    void render();
    void drawUI();

protected:
    // Singleton
    Game();
    Game(Game&) = delete;
    void operator=(const Game&) = delete;
    ~Game();

public:
    // Start and stop
    void Run();
    void Stop();

    // States
    void PushState(State* = nullptr, bool = false);

    // Singleton
    static Game* GetInstance();

    // Getters
    // double get_dt() { return deltaTime; }
    SDL_Renderer* GetRenderer() { return m_main_renderer; }
    const AssetManager* GetAssetManager() { return &m_assets; }
};
