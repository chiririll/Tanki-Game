#pragma once
#include <map>
#include <string>


class ConfigValue
{
private:
	std::string value;

public:
	ConfigValue(const std::string &value): value(value) {};
	ConfigValue(const char* value[]) : value(value[0]) {};

	std::string asString() const;
	bool asBool() const;
	int asInt() const;
	double asDouble() const;
};


class Config
{
private:
	std::string config_name;
	std::map<std::string, ConfigValue> params;

public:
	Config(std::string config_name);

	ConfigValue get(std::string key, ConfigValue default_value = ConfigValue(""));
	ConfigValue set(std::string key, ConfigValue value);

	void reload();
	void save();
};
