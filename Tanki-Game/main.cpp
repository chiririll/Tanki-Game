#include "Tanki-Game.hh"
#include "Game.h"
#include "MenuState.h"

namespace fs = std::filesystem;

void initLogger()
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

int main(int argc, char* argv[])
{	
	initLogger();

	Game* game = Game::GetInstance();
	game->PushState(new MenuState());
	game->Run();

	return 0;
}
