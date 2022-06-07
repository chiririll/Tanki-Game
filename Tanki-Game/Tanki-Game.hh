#pragma once
#include <string>
#include <filesystem>

#include <SDL_filesystem.h>

namespace fs = std::filesystem;

// Game title
#define GAME_TITLE		"Tanki!"

// Directories
const fs::path BIN_DIR(SDL_GetBasePath());
const fs::path BASE_DIR (BIN_DIR / fs::path("../../"));
const fs::path SAVES_DIR (SDL_GetPrefPath("", "TankiGame"));

const fs::path LOGS_FOLDER (SAVES_DIR / "logs");
const fs::path CONFIGS_FOLDER (SAVES_DIR / "configs");


// Logger settings
#define LOGGER_FILE_SIZE 8000000
#define LOGGER_MAX_FILES 3
