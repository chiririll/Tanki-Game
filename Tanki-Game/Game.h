#pragma once
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
    
    sf::Event event;

    sf::Clock dtClock;
    float deltaTime;
    /* ========== */
    
    /* Initialization */
    void initMainWindow();
    void initLogger();
    /* ============== */

    /* Update */
    void update();
    void render();
    void updateEvents();
    void updateDt();
    /* ====== */
};
