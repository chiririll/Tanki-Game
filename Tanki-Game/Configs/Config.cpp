#include "Config.hpp"


// Constructors & destructors
cfg::Config::Config(const string& filename): m_filename(filename)
{
	m_filepath = CONFIGS_FOLDER / (m_filename + ".json");
	Load();
}

cfg::Config::~Config()
{
	Save();
}


// Saving & loading
void cfg::Config::Load()
{
	PLOG_INFO << "Loading '" + m_filename + "' config";
	std::ifstream fin(m_filepath);

	// Leaving config empty if file does not exists
	if (fin.fail()) {
		PLOG_INFO << "Config file '" + m_filename + "' doesn't exists! Using defaults";
		return;
	}
	try {
		m_config = json::parse(fin);
	}
	catch (json::parse_error e) {
		PLOG_ERROR << "Invalid json file '" + m_filepath.string() + "': " + e.what();
	}
}

void cfg::Config::Save() const
{
	PLOG_INFO << "Saving '" + m_filename + "' config";
	std::ofstream fout(m_filepath);

	if (fout.fail()) {
		PLOG_ERROR << "Cant save config file '" + m_filepath.string() + "'";
		return;
	}

	fout << m_config;
}


// Values
void cfg::Config::SetValue(const string& key_str, const json& value) 
{
	json::json_pointer key(key_str);
	SetValue(key, value);
}

void cfg::Config::SetValue(const json::json_pointer& key, const json& value)
{
	// PLOG_DEBUG << "Adding key '" + key.to_string() + "' to config '" + m_filename + "'";
	m_config[key] = value;
}

void cfg::Config::SetDefault(const string& key_str, const json& value)
{
	json::json_pointer key(key_str);
	
	if (m_config.contains(key) && m_config[key].type_name() == value.type_name())
		return;
	
	SetValue(key, value);
}