#pragma once
#include <vector>

class Asset
{
private:
	std::vector<uint8_t> data;

protected:


public:
	Asset(int size) : data(size) {};
	virtual ~Asset() = default;
};
