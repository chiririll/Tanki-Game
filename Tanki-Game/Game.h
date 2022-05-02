#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Game
{
public:
    Game();
    ~Game();

    void run();
private:
    sf::RenderWindow* window;

    void initWindow();
    void update();
    void render();

};
