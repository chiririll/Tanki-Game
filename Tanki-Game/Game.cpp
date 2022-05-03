#include "Game.h"

Game::Game()
{
	this->initMainWindow();
	this->initLogger();
}

Game::~Game()
{
	delete this->main_window;
}

void Game::run()
{
	while (this->main_window->isOpen()) {
		this->updateEvents();
		this->updateDt();
		this->update();
		this->render();
	}
}

/* Initializers */
void Game::initMainWindow()
{
	if (this->main_window)
		return;

	this->main_window = new sf::RenderWindow(sf::VideoMode(1280, 720), GAME_TITLE, sf::Style::Titlebar | sf::Style::Close);
}

void Game::initLogger()
{
	// TODO: Initialize logger
	plog::init(plog::debug, "logs/test.log");
}
/* ============ */

/* Update */
void Game::update()
{
	PLOG_INFO << "FPS: " << 1 / this->deltaTime;
}

void Game::render()
{
	this->main_window->clear();

	// Render some stuff

	this->main_window->display();
}

void Game::updateEvents()
{
	while (this->main_window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->main_window->close();
			break;
		}
	}
}

void Game::updateDt()
{
	this->deltaTime = this->dtClock.restart().asSeconds();
}
/* ====== */