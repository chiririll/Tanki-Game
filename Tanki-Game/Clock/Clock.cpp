#include "Clock.h"

/* ===== Time ===== */

// Casting
double Time::asSeconds()
{
    return 0.0;
}

double Time::asMillis()
{
    return 0.0;
}

double Time::asMicros()
{
    return 0.0;
}

Uint64 Time::asTicks()
{
    return value;
}

// Math operators
Time Time::operator+(const Time &summand)  const
{
    return Time(this->value + summand.value);
}

Time Time::operator+=(const Time &summand)
{
    this->value += summand.value;
    return *this;
}

Time Time::operator-(const Time &subtrahend) const
{
    return Time(this->value - subtrahend.value);
}

Time Time::operator-=(const Time &subtrahend)
{
    this->value -= subtrahend.value;
    return *this;
}

// Logical operators
bool Time::operator==(const Time &compare) const
{
    return this->value == compare.value;
}

bool Time::operator<(const Time &compare) const
{
    return this->value < compare.value;
}

/* ================ */


/* ===== Clock ===== */

// Controls
void Clock::start()
{
    if (is_running)
        return;
    
    start_time = SDL_GetTicks64();
    is_running = true;
}

Time Clock::stop()
{
    is_running = false;
    return getTime();
}

Time Clock::reset()
{
    stop();
    start();
    return value;
}


// Variables
Time Clock::getTime()
{
    if (is_running)
        value = Time(SDL_GetTicks64() - start_time);
    
    return value;
}

bool Clock::isRunning()
{
    return is_running;
}
/* ================= */
