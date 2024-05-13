#include "Person.hpp"

#include <iostream>
#include <stdexcept>
#include <cstring>

unsigned short Person::numberOfGuests = 0;

Person::Person()
    : name(nullptr), id(USHRT_MAX), age(0), gender(MALE), maritalStatus(SINGLE), guestStatus(GUEST)
{ }

Person::Person(const char* name, const Gender& gender, unsigned short age, const MaritalStatus& maritalStatus, const GuestStatus& guestStatus)
    : name(nullptr), age(age), gender(gender), maritalStatus(maritalStatus), guestStatus(guestStatus)
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
    this->id = this->numberOfGuests++;
}

Person::Person(const Person& other)
    : name(nullptr)
{
    this->Copy(other);
    this->numberOfGuests++;
}

Person::Person(Person&& other)
    : name(nullptr)
{
    this->Move(std::move(other));
}

Person::~Person()
{
    this->Deallocate();
    this->numberOfGuests--;
}

Person& Person::operator=(const Person& other)
{
    if(this != &other)
    {
        this->Deallocate();
        this->Copy(other);
    }
    return *this;
}

Person& Person::operator=(Person&& other)
{
    if(this != &other)
    {
        this->Deallocate();
        this->Move(std::move(other));
    }
    return *this;
}

const char* Person::GetName() const
{
    return this->name;
}

unsigned short Person::GetId() const
{
    return this->id;
}

unsigned short Person::GetAge() const
{
    return this->age;
}

unsigned short Person::GetNumberOfGuests() const
{
    return this->numberOfGuests;
}

const char* Person::GetGender() const
{
    switch(this->gender)
    {
        case MALE:   return "male";
        case FEMALE: return "female";
    };
    throw std::logic_error("Invalid gender!");
}

const char* Person::GetMaritalStatus() const
{
    switch(this->maritalStatus)
    {
        case SINGLE:  return "single";
        case BOUND:   return "bound";
        case MARRIED: return "married";
    };
    throw std::logic_error("Invalid marital status!");
}

const char* Person::GetGuestStatus() const
{
    switch(this->guestStatus)
    {
        case BRIDEGROOM: return "bridegroom";
        case BRIDE:      return "bride";
        case GUEST:      return "guest";
        case PRIEST:     return "priest";
    };
    throw std::logic_error("Invalid guest status!");
}

void Person::SetName(const char* name)
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

void Person::SetMaritalStatus(const MaritalStatus& maritalStatus)
{
    this->maritalStatus = maritalStatus;
}

void Person::Print() const
{
    std::cout << "name: "           << (this->name ? this->name : "") << std::endl
              << "gender: "         << this->GetGender()              << std::endl
              << "age: "            << this->age                      << std::endl
              << "marital status: " << this->GetMaritalStatus()       << std::endl
              << "guest status: "   << this->GetGuestStatus()         << std::endl
              << "guest id: "       << this->id                       << std::endl;
}

void Person::Copy(const Person& other)
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

    this->gender = other.gender;
    this->age = other.age;
    this->maritalStatus = other.maritalStatus;
    this->guestStatus = other.guestStatus;
    this->id = other.id;
}

void Person::Deallocate()
{
    delete[] this->name;
    this->name = nullptr;
}

void Person::Move(Person&& other)
{
    this->name = other.name;
    other.name = nullptr;

    this->id = other.id;
    other.id = USHRT_MAX;

    this->age = other.age;
    other.age = 0;

    this->gender = other.gender;
    other.gender = MALE;

    this->maritalStatus = other.maritalStatus;
    other.maritalStatus = SINGLE;

    this->guestStatus = other.guestStatus;
    other.guestStatus = GUEST;
}
