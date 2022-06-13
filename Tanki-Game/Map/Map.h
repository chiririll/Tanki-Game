#pragma once
#include <string>
#include <vector>

#include <SDL.h>

#include <nlohmann/json.hpp>
#include <tmxlite/Map.hpp>

using std::string;
using nlohmann::json;

class Map
{
private:
	tmx::Map m_map_data;

public:
	Map(tmx::Map&& map_data) : m_map_data(std::move(map_data)) {};

	void Render(const int& scale, const uint32_t& pos_x = 0, const uint32_t& pos_y = 0);
};

