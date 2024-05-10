#include <iostream>

#include "Date.hpp"
#include "Person.hpp"
#include "Table.hpp"
#include "Wedding.hpp"

int main()
{
    Person bride("Chochka", Person::FEMALE, 25, Person::BOUND, Person::BRIDE);
    Person bridegroom("Chochko", Person::MALE, 25, Person::BOUND, Person::BRIDEGROOM);

    Wedding wedding(bride, bridegroom, "Sofia", Date(15, 8, 2024));
    
    wedding.AddGuest(0, bride);
    wedding.AddGuest(0, bridegroom);

    try
    {
        wedding.Print();
    }
    catch(const std::logic_error& e)
    {
        std::cerr << e.what() << '\n';
    }

    Marry(bridegroom, bride);

    try
    {
        bride.Print();
        bridegroom.Print();
    }
    catch(const std::logic_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
