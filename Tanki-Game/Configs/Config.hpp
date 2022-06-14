#pragma once
#include <string>
#include <fstream>

#include <nlohmann/json.hpp>
#include <plog/Log.h>

#include "ConfigValues.hpp"
#include "../Tanki-Game.hh"

using json = nlohmann::json;
using std::string;

namespace cfg
{
	class Config
	{
	private:
		json m_config;

		fs::path m_filepath;
		string m_filename;

	protected:
		void SetDefault(const string& key, const json& value);

		template <typename T>
		void InitValue(const json::json_pointer& key, ConfigValue<T>* value);
		template <typename T>
		void InitValue(const string& key, ConfigValue<T>* value);

	public:
		// Con & dest
		Config(const string& filename);
		virtual ~Config();

		// Setters
		void SetValue(const string& key, const json& value);
		void SetValue(const json::json_pointer& key, const json& value);
		
		// Getters
		template <typename T>
		T GetValue(const string& key) const;
		
		// Load & Save
		void Load();
		void Save() const;
	};
}


// Values
template<typename T>
inline void cfg::Config::InitValue(const json::json_pointer& key, ConfigValue<T>* value)
{
	if (m_config.contains(key))
		try {
			value->Set(m_config[key].get<T>());
		} catch (json::type_error) {}

	SetValue(key, value->Get());
}

template<typename T>
inline void cfg::Config::InitValue(const string& key_str, ConfigValue<T>* value)
{
	json::json_pointer key(key_str);
	InitValue(key, value);
}


template <typename T>
inline T cfg::Config::GetValue(const string& key) const
{
	json::json_pointer ptr(key);

	if (m_config.contains(ptr))
		return m_config[ptr].get<T>();

	PLOG_ERROR << "Can't get value '" + key + "' in config '" + m_filename + "'";
	throw std::invalid_argument("Can't get value '" + key + "' in config '" + m_filename);
}