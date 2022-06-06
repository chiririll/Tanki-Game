#pragma once
#include <string>
#include <fstream>

#include <nlohmann/json.hpp>
#include <plog/Log.h>

#include "../Tanki-Game.hh"

using json = nlohmann::json;
using std::string;

namespace cfg
{
	class Config
	{
	private:
		string m_filepath;
		string m_filename;

	protected:
		json m_config;

		void setDefault(const string& key, json value);

	public:
		// Con & dest
		Config(const string& filename);
		virtual ~Config();

		// Values
		void SetValue(const string& key, const json& value);

		// Load & Save
		void Load();
		void Save() const;
	};
}
