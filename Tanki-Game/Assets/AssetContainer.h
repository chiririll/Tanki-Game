#pragma once
#include <string>

#include <plog/Log.h>

#include "Asset.h"

using std::string;

class AssetContainer
{
private:

protected:
	bool valid;

public:
	// Con & destr
	AssetContainer(): valid(true) {};
	virtual ~AssetContainer() = default;
	
	// Status
	bool isValid();

	// Assets operations
	virtual Asset* GetAsset(const string& name) = 0;
	virtual bool HasAsset(const string& name) = 0;
};

