#pragma once
#include <string>
#include <vector>

#include <SDL.h>

#include <nlohmann/json.hpp>
// #include <tileson_min.hpp>

using std::string;
using nlohmann::json;

class Map
{
private:
	// tson::Map m_map;

public:
	Map();

	void Render(const int& scale, const uint32_t& pos_x = 0, const uint32_t& pos_y = 0);
};

