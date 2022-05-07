#pragma once
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <plog/Log.h>
#include "plog/Initializers/RollingFileInitializer.h"
#include "plog/Appenders/ColorConsoleAppender.h"

#include "Tanki-Game.hh"


class Game
{
private:
    // Singletone 
    static Game* pinstance_;

    /*  Variables */
    sf::RenderWindow* main_window;

    sf::Clock dtClock;
    float deltaTime;
    /* ========== */

    /* Initialization */
    void initMainWindow();
    void initLogger();
    /* ============== */

    /* Update */
    void updateEvents();
    void updateDt();
    void update();
    void render();
    /* ====== */

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
