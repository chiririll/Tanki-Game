#include "Game.h"

/* Singletone stuff */
Game* Game::pinstance_{ nullptr };

Game* Game::GetInstance()
{
	if (pinstance_ == nullptr) {
		pinstance_ = new Game();
	}
	return pinstance_;
}
/* ================ */


/* Constructors & destructors */
Game::Game()
{
	this->initLogger();
	this->initMainWindow();
}

Game::~Game()
{	
	delete this->main_window;
}
/* ========================== */


/* Game Loop */
void Game::run()
{
	while (this->main_window->isOpen()) {
		this->updateEvents();
		this->updateDt();
		this->update();
		this->render();
	}
}
/* ========= */


/* Initializers */
void Game::initMainWindow()
{
	PLOG_INFO << "Initializing main window";
	if (this->main_window)
		return;

	this->main_window = new sf::RenderWindow(sf::VideoMode(1280, 720), GAME_TITLE, sf::Style::Titlebar | sf::Style::Close);
	PLOG_INFO << "Main window created";
}

void Game::initLogger()
{
	// TODO: Create logs folder
	
	// Log file path
	std::string filename = LOGS_FOLDER + "tanki.log";

	// Adding file appender
	static plog::RollingFileAppender<plog::TxtFormatter> fileAppender(&filename[0], LOGGER_FILE_SIZE, LOGGER_MAX_FILES);
	// Adding console appender
	static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;
	
	// Initializing logger
	plog::init(plog::debug, &fileAppender).addAppender(&consoleAppender);

	PLOG_INFO << "Logger initialized";
}
/* ============ */


/* Update */
void Game::update()
{
	// PLOG_INFO << "FPS: " << 1 / this->deltaTime;
}

void Game::render()
{
	this->main_window->clear();

	// Render some stuff

	this->main_window->display();
}

void Game::updateEvents()
{
	// TODO: EventListener pattern

	sf::Event event;
	while (this->main_window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			PLOG_INFO << "Closing main window";
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