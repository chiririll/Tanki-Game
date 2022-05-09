#include "Game.h"


// Singletone stuff 
Game* Game::pinstance_{ nullptr };
std::mutex Game::mutex_;

Game* Game::GetInstance()
{
	std::lock_guard<std::mutex> lock(mutex_);
	if (pinstance_ == nullptr) {
		pinstance_ = new Game();
	}
	return pinstance_;
}


// Constructors & destructors
Game::Game()
{
	this->initLogger();

	// Initializing SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
		PLOG_ERROR << "Can't initialize SDL";
		return;
	}

	this->initMainWindow();
}

Game::~Game()
{	
	SDL_Quit();
}


// Game Loop 
void Game::run()
{
	while (this->main_window) {
		this->updateDt();
		this->updateEvents();
		this->update();
		this->render();
	}
}


// Initializers 
void Game::initMainWindow()
{
	if (this->main_window != nullptr) {
		PLOG_WARNING << "Attempted second time window initialization";
		return;
	}

	PLOG_INFO << "Initializing main window";

	this->main_window = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);

	if (this->main_window == nullptr)
		PLOG_ERROR << "Can't create main window";
	else
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


// Update
void Game::update()
{
	// PLOG_INFO << "FPS: " << 1 / this->deltaTime;
}

void Game::render()
{
	// this->main_window->clear();

	// Render some stuff

	// this->main_window->display();
}

void Game::updateEvents()
{
	// TODO: EventListener pattern

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			PLOG_INFO << "Closing main window";
			SDL_DestroyWindow(this->main_window);
			this->main_window = nullptr;
			break;
		}
	}
}

void Game::updateDt()
{
	Uint64 dt_now = SDL_GetPerformanceCounter();
	
	deltaTime = (double)((dt_now - dt_last) * 1000 / (double)SDL_GetPerformanceFrequency());

	dt_last = dt_now;
}
