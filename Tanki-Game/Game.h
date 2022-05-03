#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Tanki-Game.h"


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
    
    /* ============== */

    /* Update */
    void update();
    void render();
    void updateEvents();
    /* ====== */
};
