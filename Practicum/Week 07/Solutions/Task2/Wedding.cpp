#include "Wedding.hpp"

#include <iostream>
#include <stdexcept>
#include <cstring>

Wedding::Wedding(const Person& bride, const Person& bridegroom, const char* location, const Date& date)
    : location(nullptr), date(date), bride(bride), bridegroom(bridegroom)
{ 
    try
    {
        this->SetLocation(location);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << " No location set!" << std::endl;
    }

    for(unsigned short i = 0; i < MAX_NUM_OF_TABLES; i++)
    {
        char name[8] = "Table0";
        if(i < 10)
        {
            name[6] = '0' + i;
        }
        else
        {
            name[5] = '0' + (i / 10) % 10 ;
            name[6] = '0' + i % 10;
        }
        name[7] = '\0';

        this->tables[i].SetName(name);
    } 
}

Wedding::~Wedding()
{
    delete[] this->location;
    this->location = nullptr;
}

const char* Wedding::GetLocation() const
{
    return this->location;
}

Date Wedding::GetDate() const
{
    return this->date;
}

void Wedding::SetLocation(const char* location)
{
    if(!location) throw std::invalid_argument("Invalid location!");

    delete[] this->location;

    this->location = new(std::nothrow) char[strlen(location) + 1];
    if(!this->location)
    {
        throw std::bad_alloc();
    }
    strcpy(this->location, location);
}

void Wedding::SetDate(const Date& date)
{
    this->date = date;
}

void Wedding::ChangeGuest(unsigned short tableIndex, unsigned short guestIndex, const Person& newGuest)
{
    if(tableIndex >= MAX_NUM_OF_TABLES)
        throw std::out_of_range("Invalid index!");

    try
    {
        this->tables[tableIndex].ChangeGuest(guestIndex, newGuest);
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << " Try again!" << std::endl;
    }
}

void Wedding::AddGuest(unsigned short tableIndex, const Person& guest)
{
    if(tableIndex >= MAX_NUM_OF_TABLES)
        throw std::out_of_range("Invalid index!");

    this->tables[tableIndex].AddGuest(guest);
}

void Wedding::SwapGuests(unsigned short tableIndex, unsigned short guestIndex1, unsigned short guestIndex2)
{
    if(tableIndex >= MAX_NUM_OF_TABLES)
        throw std::out_of_range("Invalid index!");

    try
    {
        this->tables[tableIndex].SwapGuests(guestIndex1, guestIndex2);
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << " Try again!" << std::endl;
    }
}

void Wedding::Print() const
{
    std::cout << "BRIDE:\n";      this->bride.Print();
    std::cout << "BRIDEGROOM:\n"; this->bridegroom.Print();
    std::cout << "DATE: ";       this->date.Print();
    std::cout << "LOCATION: "   << (this->location ? this->location : "") << std::endl;

    std::cout << "==============================" << std::endl
              << "GUEST SEATS:"                   << std::endl;

    for(unsigned short i = 0; i < MAX_NUM_OF_TABLES; i++)
    {
        if(this->tables[i].GetNumberOfGuests() > 0)
            this->tables[i].Print();
        else
            std::cout << "empty" << std::endl;
        std::cout << "==============================" << std::endl;
    }
}

void Wedding::Blessing(Person& bridegroom, Person& bride)
{
    std::cout << "Married!" << std::endl;
}

void Marry(Person& bridegroom, Person& bride)
{
    Wedding::Blessing(bridegroom, bride);
    bridegroom.SetMaritalStatus(Person::MARRIED);
    bride.SetMaritalStatus(Person::MARRIED);
}
