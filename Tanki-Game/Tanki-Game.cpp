#include <SFML/Graphics.hpp>
#include "Game.h"


int main(int argc, char* argv[])
{
	Game game;
	
	game.run();

	return 0;
}

//int main(int argc, char* argv[])
//{
//    // TODO: handle startup options
//
//    sf::RenderWindow window(sf::VideoMode(1280, 720), "Tanki!", sf::Style::Titlebar | sf::Style::Close);
//    
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Yellow);
//
//    while (window.isOpen())
//    {
//        
//
//        window.clear();
//        
//        window.draw(shape);
//        // TODO: Game
//        
//        window.display();
//    }
//
//    return 0;
//}
