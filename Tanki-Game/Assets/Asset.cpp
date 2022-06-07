#include "Asset.h"

Asset::Asset(int size) : size(size)
{
	data = new char[size];
}
