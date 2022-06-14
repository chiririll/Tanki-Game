#include "Map.h"

Map::Map(tmx::Map&& map_data) : m_map_data(std::move(map_data)) 
{

};
