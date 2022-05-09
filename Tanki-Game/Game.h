#pragma once
#include <string>
#include <mutex>
#include <filesystem>

#include <SDL.h>

#include <plog/Log.h>
#include "plog/Initializers/RollingFileInitializer.h"
#include "plog/Appenders/ColorConsoleAppender.h"

#include "Tanki-Game.hh"

namespace fs = std::filesystem;

#define GAME Game::GetInstance()

class Game
{
private:
    // Singletone 
    static Game* pinstance_;
    static std::mutex mutex_;

    // Variables 
    SDL_Window* main_window;
    SDL_Renderer* main_renderer;

    // Delta time
    Uint64 dt_last = 0;
    double deltaTime;

    // Initialization 
    void initMainWindow();
    void initMainRenderer();
    void initLogger();
    void initConfigs();

    // Update 
    void updateEvents();
    void updateDt();
    void update();
    void render();

protected:
    Game();
    ~Game();

public:
    // Start and stop
    void run();
    void stop();

    // Singletone 
    Game(Game& other) = delete;
    void operator=(const Game&) = delete;
    static Game* GetInstance();

    // Variables
    inline double get_dt() { return deltaTime; }
};
