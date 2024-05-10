#include "Date.hpp"

#include <iostream>
#include <stdexcept>

const unsigned short DAYS_IN_MONTH[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date(unsigned short day, unsigned short month, unsigned short year)
{
    if(month < 1 || month > 12) 
        throw std::invalid_argument("Invalid month!");

    if((month == 2 && IsLeapYear(year) && (day < 1 || day > DAYS_IN_MONTH[month - 1] + 1)) ||
       (month == 2 && !IsLeapYear(year) && (day < 1 || day > DAYS_IN_MONTH[month - 1]))    ||
       (month != 2 && (day < 1 || day > DAYS_IN_MONTH[month - 1])))
    {
        throw std::invalid_argument("Invalid day!");
    }

    this->day = day;
    this->month = month;
    this->year = year;
}

unsigned short Date::GetDay() const
{
    return this->day;
}

unsigned short Date::GetMonth() const
{
    return this->month;
}

unsigned short Date::GetYear() const
{
    return this->year;
}

void Date::Print() const
{
    std::cout << (this->day < 10 ? "0" : "")   << this->day   << '.'
              << (this->month < 10 ? "0" : "") << this->month << '.'
              << this->year                    << std::endl;
}

bool Date::IsLeapYear(unsigned short year)
{
    return (year % 4 == 0) && ((year % 400 == 0) || (year % 100 != 0));
}
