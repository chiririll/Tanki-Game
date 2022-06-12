#pragma once
#include <string>
#include <vector>

#include <SDL.h>

#include <nlohmann/json.hpp>
//#include <tileson.hpp>

using std::string;
using nlohmann::json;

class Map
{
private:
	

public:
	Map();

	void Render(const int& scale, const uint32_t& pos_x = 0, const uint32_t& pos_y = 0);
};

