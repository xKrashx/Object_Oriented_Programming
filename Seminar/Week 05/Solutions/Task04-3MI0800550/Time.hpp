#pragma once
#include <iostream>

class Time
{
private:
    unsigned seconds;
public:
    Time();
    Time(unsigned seconds);
    Time(unsigned hours,unsigned minutes,unsigned seconds);
    Time LeftUntilMidnight();
    void PlusSecond();
    void PlusSecond(unsigned seconds);
    bool IsTimeForDinner();
    bool IsTimeForParty();
    Time TimeSubtract(const Time other);
    Time operator-(const Time other);
    bool CompareTimes(const Time other);
    friend std::ostream &operator<<(std::ostream &out, const Time &time);
    

};

