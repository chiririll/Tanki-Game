#pragma once
// C++ libs
#include <string>
#include <filesystem>
#include <map>

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


#define GAME Game::GetInstance()

namespace fs = std::filesystem;


class Game
{
private:
    // Singleton
    static Game* pinstance_;

    // Variables 
    SDL_Window* m_main_window;
    SDL_Renderer* m_main_renderer;
    State* m_state;

    // TODO: Configs

    // Delta time
    Uint64 dt_last;
    double deltaTime;

    // Initialization 
    void initMainWindow();
    void initMainRenderer();
    void initLogger();
    void initConfigs();

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
    inline double get_dt() { return deltaTime; }
    inline SDL_Renderer* GetRenderer() { return m_main_renderer; }
};
