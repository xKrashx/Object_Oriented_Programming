#include "Table.hpp"

#include <iostream>
#include <stdexcept>
#include <cstring>

Table::Table() : name(nullptr), numberOfGuests(0)
{ }

Table::Table(const char* name) 
    : name(nullptr), numberOfGuests(0)
{
    try
    {
        this->SetName(name);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << " The length must be <= " << MAX_NAME_LEN << " characters!" << std::endl;
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << " No name set!" << std::endl;
    }
}

Table::Table(const Table& other)
    : name(nullptr)
{
    this->Copy(other);
}

Table::Table(Table&& other)
    : name(nullptr)
{
    this->Move(std::move(other));
}

Table::~Table()
{
    this->Deallocate();
}

Table& Table::operator=(const Table& other)
{
    if(this != &other)
    {
        this->Deallocate();
        this->Copy(other);
    }
    return *this;
}

Table& Table::operator=(Table&& other)
{
    if(this != &other)
    {
        this->Deallocate();
        this->Move(std::move(other));
    }
    return *this;
}

const char* Table::GetName() const
{
    return this->name;
}

unsigned short Table::GetNumberOfGuests() const
{
    return this->numberOfGuests;
}

void Table::SetName(const char* name)
{
    const unsigned short nameLen = strlen(name);
    
    if(!name || nameLen > MAX_NAME_LEN) 
        throw std::invalid_argument("Invalid name!");

    delete[] this->name;

    this->name = new(std::nothrow) char[nameLen + 1];
    if(!this->name)
    {
        throw std::bad_alloc();
    }
    strcpy(this->name, name);
}

Person Table::ChangeGuest(unsigned short index, const Person& newGuest)
{
    if(index >= MAX_GUESTS)
        throw std::out_of_range("Invalid index!");

    Person temp = this->guests[index];
    this->guests[index] = newGuest;
    return temp;
}

void Table::AddGuest(const Person& guest)
{
    if(this->numberOfGuests >= MAX_GUESTS)
    {
        std::cout << "The table is full!" << std::endl;
        return;
    }
    this->guests[this->numberOfGuests++] = guest;
}

void Table::SwapGuests(unsigned short index1, unsigned short index2)
{
    if(index1 >= MAX_GUESTS || index2 >= MAX_GUESTS || index1 == index2)
        throw std::out_of_range("Invalid indices!");

    Person temp(this->guests[index1]);
    this->guests[index1] = this->guests[index2];
    this->guests[index2] = temp;
}

void Table::Print() const
{
    std::cout << "table name: "       << (this->name ? this->name : "") << std::endl
              << "number of guests: " << this->numberOfGuests           << std::endl
              << "guests:\n";

    for(unsigned short i = 0; i < MAX_GUESTS; i++)
    {
        if(this->guests[i].GetName() != nullptr)
            this->guests[i].Print();
        else
            std::cout << "empty" << std::endl;
        std::cout << "------------------------------" << std::endl;
    }
}

void Table::Copy(const Table& other)
{
    try
    {
        this->SetName(other.name);
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << e.what() << " The length must be <= " << MAX_NAME_LEN << " characters!" << std::endl;
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << e.what() << " No name set!" << std::endl;
    }
    
    this->numberOfGuests = other.numberOfGuests;

    for(unsigned short i = 0; i < MAX_GUESTS; i++)
    {
        if(other.guests[i].GetName() != nullptr)
            this->guests[i] = other.guests[i];
    }
}

void Table::Deallocate()
{
    delete[] this->name;
    this->name = nullptr;
}

void Table::Move(Table&& other)
{
    this->name = other.name;
    other.name = nullptr;

    this->numberOfGuests = other.numberOfGuests;
    other.numberOfGuests = 0;

    for(unsigned short i = 0; i < MAX_GUESTS; i++)
    {
        this->guests[i] = other.guests[i];
        other.guests[i] = Person();
    }
}
