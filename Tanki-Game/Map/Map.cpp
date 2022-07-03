#include "Map.h"

Map::Map(tmx::Map&& map_data) : m_map_data(std::move(map_data)) 
{

}

void Map::Render(const int& scale, const uint32_t& pos_x, const uint32_t& pos_y)
{

}

