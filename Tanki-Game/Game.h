#pragma once
#include <string>
#include <mutex>

#include <SDL.h>

#include <plog/Log.h>
#include "plog/Initializers/RollingFileInitializer.h"
#include "plog/Appenders/ColorConsoleAppender.h"

#include "Tanki-Game.hh"


#define GAME Game::GetInstance()

class Game
{
private:
    // Singletone 
    static Game* pinstance_;
    static std::mutex mutex_;

    // Variables 
    SDL_Window* main_window;

    // Delta time
    Uint64 dt_last = 0;
    double deltaTime;

    // Initialization 
    void initMainWindow();
    void initLogger();

    // Update 
    void updateEvents();
    void updateDt();
    void update();
    void render();

protected:
    Game();
    ~Game();

public:
    void run();

    // Singletone 
    Game(Game& other) = delete;
    void operator=(const Game&) = delete;
    static Game* GetInstance();
};
