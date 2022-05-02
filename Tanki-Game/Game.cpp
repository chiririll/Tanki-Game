#include "Game.h"

Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::run()
{
	while (this->window->isOpen()) {
		this->update();
		this->render();
	}
}

void Game::initWindow()
{
	if (this->window)
		return;

	this->window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Tanki!", sf::Style::Titlebar | sf::Style::Close);
}

void Game::update()
{
	sf::Event event;
	while (this->window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		}
	}
}

void Game::render()
{
	this->window->clear();

	// Render some stuff

	this->window->display();
}
