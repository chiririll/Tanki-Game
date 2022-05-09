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
	initLogger();

	// Initializing SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
		PLOG_ERROR << "Can't initialize SDL";
		std::exit(1);
	}

	initConfigs();
	initMainWindow();
	initMainRenderer();
}

Game::~Game()
{	
	SDL_Quit();
}


// Game Loop 
void Game::run()
{
	while (main_window) {
		updateDt();
		updateEvents();
		update();
		render();
	}
}


// Stopper
void Game::stop()
{
	PLOG_INFO << "Destroying renderer";
	SDL_DestroyRenderer(main_renderer);

	PLOG_INFO << "Closing main window";
	SDL_DestroyWindow(main_window);
	main_window = nullptr;
}


// Initializers 
void Game::initMainWindow()
{
	if (main_window != nullptr) {
		PLOG_WARNING << "Attempted second time window initialization";
		return;
	}

	PLOG_INFO << "Initializing main window";

	main_window = SDL_CreateWindow(GAME_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_SHOWN);

	if (main_window == nullptr) {
		PLOG_ERROR << "Can't create main window";
		std::exit(2);
	}
	PLOG_INFO << "Main window created";
}

void Game::initMainRenderer()
{
	main_renderer = SDL_CreateRenderer(main_window, -1, SDL_RENDERER_ACCELERATED);
	if (not main_renderer) {
		PLOG_ERROR << "Can't initialize main renderer";
		std::exit(3);
	}
}

void Game::initLogger()
{
	// Creating logs folder
	fs::create_directory(LOGS_FOLDER);
	
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

void Game::initConfigs()
{
	// TODO: load config files
}


// Update
void Game::update()
{
	// PLOG_INFO << "FPS: " << 1 / deltaTime;
}

void Game::render()
{
	SDL_RenderClear(main_renderer);
	
	// Render some stuff

	SDL_RenderPresent(main_renderer);
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
			this->stop();
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
