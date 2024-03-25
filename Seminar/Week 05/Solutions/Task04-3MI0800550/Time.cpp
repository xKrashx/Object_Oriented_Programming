#include "Time.hpp"

Time::Time()
{
    this->seconds = 0;
}

Time::Time(unsigned seconds)
{
    this->seconds = seconds;
}

Time::Time(unsigned hours, unsigned minutes, unsigned seconds)
{
    this->seconds = 0;
    this->seconds += hours * 3600 + minutes * 60 + seconds;
}

Time Time::LeftUntilMidnight()
{
    unsigned midnight_in_sec = 24 * 3600;

    return Time(midnight_in_sec - this->seconds);
}

void Time::PlusSecond()
{
    this->seconds++;
}

void Time::PlusSecond(unsigned seconds)
{
    this->seconds += seconds;
}

bool Time::IsTimeForDinner()
{
    Time time_for_dinner_start(20, 30, 0);
    Time time_for_dinner_end(22, 0, 0);
    if (this->seconds >= time_for_dinner_start.seconds && this->seconds <= time_for_dinner_end.seconds)
        return true;
    else
        return false;
}

bool Time::IsTimeForParty()
{
    Time time_for_party_start(23, 0, 0);
    Time time_for_party_end(6, 0, 0);

    if (this->seconds >= time_for_party_start.seconds && this->seconds <= time_for_party_end.seconds)
        return true;
    else
        false;
}

Time Time::TimeSubtract(const Time other)
{
    if (this->seconds > other.seconds)
    {
        return Time(24 * 3600 - (this->seconds - other.seconds));
    }
    else
        return Time(other.seconds - this->seconds);
}

Time Time::operator-(const Time other)
{
    if (this->seconds > other.seconds)
    {
        return Time(24 * 3600 - (this->seconds - other.seconds));
    }
    else
        return Time(other.seconds - this->seconds);
}

bool Time::CompareTimes(const Time other)
{
    if (this->seconds > other.seconds)
    {
        return true;
    }
    else
        return false;
}

std::ostream &operator<<(std::ostream &out, const Time &time)
{
    unsigned Sec = time.seconds % 60;
    unsigned Min = (time.seconds % 3600) / 60;
    unsigned Hrs = time.seconds / 3600;
    out << Hrs << ':' << Min << ':' << Sec;
    return out;
}
