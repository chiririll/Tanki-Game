#include <filesystem>

#include "Tanki-Game.hh"
#include "Game.h"
#include "States/MenuState.h"


void initLogger()
{
	// Creating logs folder
	std::filesystem::create_directory(LOGS_FOLDER);

	// Log file path
	fs::path file = LOGS_FOLDER / fs::path("tanki.log");

	// Adding file appender
	static plog::RollingFileAppender<plog::TxtFormatter> fileAppender(file.c_str(), LOGGER_FILE_SIZE, LOGGER_MAX_FILES);
	// Adding console appender
	static plog::ColorConsoleAppender<plog::TxtFormatter> consoleAppender;

	// Initializing logger
	plog::init(plog::debug, &fileAppender).addAppender(&consoleAppender);

	PLOG_INFO << "Logger initialized";
}

int main(int argc, char* argv[])
{	
	initLogger();

	Game* game = Game::GetInstance();
	game->PushState(new MenuState());
	game->Run();

	return 0;
}
