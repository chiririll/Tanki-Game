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
Game::Game(): m_gfx_conf(), m_sound_conf()
{
	// Initializing SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) != 0) {
		PLOG_ERROR << "Can't initialize SDL: " << SDL_GetError();
		exit(1);
	}

	initFolders();
	initMainWindow();
	initMainRenderer();
	initAssets();
	initAudio();
}

Game::~Game()
{
	SDL_Quit();
}


// Game Loop 
void Game::Run()
{
	// Update
	Uint64 prev_update = SDL_GetPerformanceCounter();
	Uint64 next_update = SDL_GetPerformanceCounter();
	double delta_time = 0.16f;

	// TODO

	// TODO: Handle runtime errors
	while (m_main_window != nullptr) {
		updateEvents();
		update(prev_update, next_update, delta_time);
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
	m_main_renderer = SDL_CreateRenderer(m_main_window, -1, SDL_RENDERER_ACCELERATED | m_gfx_conf.render_flags());
	if (not m_main_renderer) {
		PLOG_ERROR << "Can't initialize main renderer: " << SDL_GetError();
		std::exit(3);
	}
	m_assets.SetRenderer(m_main_renderer);
}

void Game::initAssets()
{
	// Adding containers
	m_assets.AddContainer(new FolderContainer());
}

void Game::initAudio()
{
	// Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		PLOG_ERROR << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError();
		std::exit(4);
	}
}

void Game::initFolders()
{
	fs::create_directory(LOGS_FOLDER);
	fs::create_directory(CONFIGS_FOLDER);
}

// Update
void Game::update(Uint64& prev_update, Uint64& next_update, double& delta_time)
{
	// FIXME: Overflow?
	if (SDL_GetPerformanceCounter() < next_update) {
		return;
	}

	// PLOGD << "FPS: " << 1 / delta_time;

	// Updating states
	m_state->Update(delta_time);

	next_update += m_gfx_conf.frame_time();
	
	// Rendering changes
	render();

	delta_time = (double)(SDL_GetPerformanceCounter() - prev_update) / (double)SDL_GetPerformanceFrequency();
	prev_update = SDL_GetPerformanceCounter();
}

void Game::render()
{
	// TODO: calc deltatime and limit fps
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
		case SDL_KEYDOWN:
			//this->Stop();
			break;
		case SDL_WINDOWEVENT:
			handleWindowEvent(event.window.event);
			break;
		}
	}
}

void Game::handleWindowEvent(Uint8 window_event)
{
	switch (window_event) {
	case SDL_WINDOWEVENT_FOCUS_LOST:
		if (m_sound_conf.MuteMusicFocus())
			Mix_VolumeMusic(0);
		if (m_sound_conf.MuteSoundFocus())
			Mix_Volume(-1, 0);
		break;
	case SDL_WINDOWEVENT_FOCUS_GAINED:
		Mix_VolumeMusic(m_sound_conf.GetMusicVolume());
		Mix_Volume(-1, m_sound_conf.GetSoundVolume());
		break;
	}
}

// State
void Game::PushState(State* state, bool is_menu)
{
	if (state == nullptr)
		return;

	if (m_state != nullptr)
		delete m_state;

	m_state = state;
	m_state->AddAssetManager(&m_assets);

	// Trying to start state
	bool succeed = false;
	string error("Unknown error");
	try {
		succeed = m_state->Start();
		error = state->GetError();
	}
	catch (json::exception e) { error = e.what(); }
	catch (std::exception e) { error = e.what(); }
	catch (...) {}

	if (!succeed) {
		// Showing error
		PLOG_ERROR << "Failed to load state: " << error;
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Failed to load state", error.c_str(), m_main_window);
		
		// Pushing menu state or exiting game
		if (!is_menu) PushState(new MenuState(), true);
		else Stop();
	}
}
