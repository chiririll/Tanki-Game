#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Game
{
public:
    Game();
    ~Game();

    void run();
private:
    sf::RenderWindow* main_window;
    sf::Clock timer;

    sf::Time deltaTime;

    void initWindow();
    
    void update();
    void render();

};
