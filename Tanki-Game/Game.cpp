#include "Game.h"

Game::Game()
{
	this->initWindow();
}

Game::~Game()
{
	delete this->main_window;
}

void Game::run()
{
	while (this->main_window->isOpen()) {
		this->update();
		this->render();
	}
}

void Game::initWindow()
{
	if (this->main_window)
		return;

	this->main_window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Tanki!", sf::Style::Titlebar | sf::Style::Close);
}

void Game::update()
{
	this->deltaTime = timer.getElapsedTime();
	timer.restart();

	sf::Event event;
	while (this->main_window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			this->main_window->close();
			break;
		}
	}
}

void Game::render()
{
	this->main_window->clear();

	// Render some stuff

	this->main_window->display();
}
