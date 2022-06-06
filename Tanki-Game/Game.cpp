#include "Game.h"


// Singleton stuff 
Game* Game::pinstance_ = nullptr;

Game* Game::GetInstance()
{
	if (pinstance_ == nullptr)
		pinstance_ = new Game();
	return pinstance_;
}


// Constructors & destructors
Game::Game()
{
	// Initializing SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
		PLOG_ERROR << "Can't initialize SDL: " << SDL_GetError();
		std::exit(1);
	}

	initMainWindow();
	initMainRenderer();
}

Game::~Game()
{
	SDL_Quit();
}


// Game Loop 
void Game::Run()
{
	while (m_main_window != nullptr) {
		updateEvents();
		update();
		updateDt();
	}
	delete this;
}

// Stopper
void Game::Stop()
{
	PLOG_INFO << "Destroying renderer";
	SDL_DestroyRenderer(m_main_renderer);

	PLOG_INFO << "Closing main window";
	SDL_DestroyWindow(m_main_window);
	m_main_window = nullptr;
}


// Initializers 
void Game::initMainWindow()
{
	if (m_main_window != nullptr) {
		PLOG_WARNING << "Attempted second time window initialization";
		return;
	}

	PLOG_INFO << "Initializing main window";

	// TODO: Load params from config
	m_main_window = SDL_CreateWindow(
		GAME_TITLE, 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		m_gfx_conf.window_w(),
		m_gfx_conf.window_h(),
		SDL_WINDOW_SHOWN | m_gfx_conf.window_flags()
	);

	if (m_main_window == nullptr) {
		PLOG_ERROR << "Can't create main window: " << SDL_GetError();
		std::exit(2);
	}
	PLOG_INFO << "Main window created";
}

void Game::initMainRenderer()
{
	m_main_renderer = SDL_CreateRenderer(m_main_window, -1, SDL_RENDERER_ACCELERATED);
	if (not m_main_renderer) {
		PLOG_ERROR << "Can't initialize main renderer: " << SDL_GetError();
		std::exit(3);
	}
}

// Update
void Game::update()
{
	
	// TODO: Updating states

	// TODO: Fixed update

	m_state->Update();
	render();
	// PLOG_INFO << "FPS: " << 1 / deltaTime;
}

void Game::render()
{
	SDL_RenderClear(m_main_renderer);
	
	// Render some stuff
	m_state->Render();

	SDL_RenderPresent(m_main_renderer);
}

void Game::drawUI()
{
	m_state->DrawUI();
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
			this->Stop();
			break;
		}
	}
}

void Game::updateDt()
{	
	Uint64 now = SDL_GetPerformanceCounter();
	deltaTime = (now - dt_last) / (double)SDL_GetPerformanceFrequency();
	dt_last = now;
}


// State
void Game::PushState(State* state)
{
	if (state == nullptr)
		return;

	if (m_state != nullptr)
		delete m_state;

	m_state = state;
}
