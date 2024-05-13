#ifndef __PERSON_HPP
#define __PERSON_HPP

#include <cstdint>

class Person
{
    public:
        enum Gender : uint8_t { MALE, FEMALE };
        enum MaritalStatus : uint8_t { SINGLE, BOUND, MARRIED };
        enum GuestStatus : uint8_t { BRIDEGROOM, BRIDE, GUEST, PRIEST };

        Person();
        Person(const char* name, const Gender& gender, unsigned short age, const MaritalStatus& maritalStatus, const GuestStatus& guestStatus = GUEST);
        Person(const Person& other);
        Person(Person&& other);

        ~Person();

        Person& operator=(const Person& other);
        Person& operator=(Person&& other);

        const char* GetName() const;
        unsigned short GetId() const;
        unsigned short GetAge() const;
        unsigned short GetNumberOfGuests() const;
        
        const char* GetGender() const;
        const char* GetMaritalStatus() const;
        const char* GetGuestStatus() const;

        void SetName(const char* name);
        void SetMaritalStatus(const MaritalStatus& maritalStatus);

        void Print() const;

    private:
        char* name;
        unsigned short id;
        unsigned short age;
        Gender gender;
        MaritalStatus maritalStatus;
        GuestStatus guestStatus;

        static unsigned short numberOfGuests;
        static const unsigned short MAX_NAME_LEN = 255;

        void Copy(const Person& other);
        void Deallocate();
        void Move(Person&& other);
};

#endif
