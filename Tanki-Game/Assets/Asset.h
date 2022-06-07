#pragma once
#include <vector>

class Asset
{
private:
	unsigned int size;
	char* data;

protected:


public:
	Asset(int size);
	Asset() = default;
	virtual ~Asset() = default;
};
