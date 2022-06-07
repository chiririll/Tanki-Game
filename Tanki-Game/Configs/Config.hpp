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
		json m_config;

		string m_filepath;
		string m_filename;

	protected:
		void SetDefault(const string& key, const json& value);

	public:
		// Con & dest
		Config(const string& filename);
		virtual ~Config();

		// Values
		void SetValue(const string& key, const json& value);
		void SetValue(const json::json_pointer& key, const json& value);
		template <typename T>
		T GetValue(const string& key) const;
		
		// Load & Save
		void Load();
		void Save() const;
	};
} // namespace cfg

// Templates
template <typename T>
inline T cfg::Config::GetValue(const string& key) const
{
	PLOG_DEBUG << "Getting value '" + key + "'";

	json::json_pointer ptr(key);

	if (m_config.contains(ptr))
		return m_config[ptr].get<T>();
	
	PLOG_ERROR << "Can't get value '" + key + "' in config '" + m_filename + "'";
	throw std::invalid_argument("Can't get value '" + key + "' in config '" + m_filename);
}
