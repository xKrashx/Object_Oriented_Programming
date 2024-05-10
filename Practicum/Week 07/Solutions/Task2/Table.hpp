#ifndef __TABLE_HPP
#define __TABLE_HPP

#include "Person.hpp"

class Table
{
    public:
        Table();
        Table(const char* name);
        Table(const Table& other);
        Table(Table&& other);

        ~Table();

        Table& operator=(const Table& other);
        Table& operator=(Table&& other);

        const char* GetName() const;
        unsigned short GetNumberOfGuests() const;

        void SetName(const char* name);

        Person ChangeGuest(unsigned short index, const Person& newGuest);
        void AddGuest(const Person& guest);
        void SwapGuests(unsigned short index1, unsigned short index2);

        void Print() const;

    private:
        static const unsigned short MAX_NAME_LEN = 255;
        static const unsigned short MAX_GUESTS = 20;

        Person guests[MAX_GUESTS];
        char* name;
        unsigned short numberOfGuests;

        void Copy(const Table& other);
        void Deallocate();
        void Move(Table&& other);
};

#endif
