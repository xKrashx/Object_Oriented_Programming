#ifndef __WEDDING_HPP
#define __WEDDING_HPP

#include "Date.hpp"
#include "Table.hpp"

class Wedding
{
    public:
        Wedding(const Person& bride, const Person& bridegroom, const char* location, const Date& date);
        Wedding(const Wedding& other) = delete;
        Wedding(Wedding&& other) = delete;

        ~Wedding();

        Wedding& operator=(const Wedding& other) = delete;
        Wedding& operator=(Wedding&& other) = delete;

        const char* GetLocation() const;
        Date GetDate() const;

        void SetLocation(const char* location);
        void SetDate(const Date& date);

        void ChangeGuest(unsigned short tableIndex, unsigned short guestIndex, const Person& newGuest);
        void AddGuest(unsigned short tableIndex, const Person& guest);
        void SwapGuests(unsigned short tableIndex, unsigned short guestIndex1, unsigned short guestIndex2);

        void Print() const;

        friend void Marry(Person& bridegroom, Person& bride);

    private:
        static const unsigned short MAX_NUM_OF_TABLES = 10;

        Table tables[MAX_NUM_OF_TABLES];
        Person bridegroom, bride;
        char* location;
        Date date;

        static void Blessing(Person& bridegroom, Person& bride);
};

void Marry(Person& bridegroom, Person& bride);

#endif
