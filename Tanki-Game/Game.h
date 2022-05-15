#pragma once
#include <string>
#include <mutex>
#include <filesystem>
#include <map>

#include <SDL.h>

#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>
#include <plog/Appenders/ColorConsoleAppender.h>

#include <yaml-cpp/yaml.h>

#include "Tanki-Game.hh"
#include "State.h"


namespace fs = std::filesystem;

#define GAME Game::GetInstance()

// TODO: Refactor
class Game
{
private:
    // Singletone 
    static Game* pinstance_;
    static std::mutex mutex_;

    // Variables 
    SDL_Window* m_main_window;
    SDL_Renderer* m_main_renderer;
    State* m_state;

    // Configs
    std::map<std::string, YAML::Node> configs;

    // Delta time
    Uint64 dt_last;
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
    void Run();
    void Stop();

    // States
    void PushState();

    // Singletone 
    Game(Game&) = delete;
    void operator=(const Game&) = delete;
    static Game* GetInstance();

    // Variables
    inline double get_dt() { return deltaTime; }
};

