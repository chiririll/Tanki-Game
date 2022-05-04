#pragma once
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <plog/Log.h>
#include "plog/Initializers/RollingFileInitializer.h"

#include "Tanki-Game.hh"


// TODO: Singletone
class Game
{
public:
    Game();
    ~Game();

    void run();

private:
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
};
