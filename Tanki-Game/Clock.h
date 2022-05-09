#pragma once
#include <SDL.h>


class Time 
{
private:
	Uint64 value;
public:
	Time(Uint64 value) : value(value) {};

	// Casting
	double asSeconds();
	double asMillis();
	double asMicros();
	Uint64 asTicks();

	// Math operators
	Time operator+(const Time &summand) const;
	Time operator+=(const Time &summand);
	Time operator-(const Time &subtrahend) const;
	Time operator-=(const Time &subtrahend);

	// Logical operators
	bool operator==(const Time &compare) const;
	bool operator<(const Time &compare) const;
	bool operator!=(const Time &compare) const { return !(*this == compare); };
	bool operator>(const Time &compare) const { return !(*this < compare) && !(*this == compare); };
	bool operator<=(const Time &compare) const { return !(*this > compare); };
	bool operator>=(const Time &compare) const { return !(*this < compare); };
};


class Clock
{
private:
	Uint64 start_time;
	Time value;
	bool is_running;

public:
	Clock(bool start = true) : start_time(SDL_GetTicks64()), value(0), is_running(start) {};

	// Controls
	void start();
	Time stop();
	Time reset();

	// Variables
	Time getTime();
	bool isRunning();
};

