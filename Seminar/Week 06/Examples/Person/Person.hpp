#pragma once

class Person{

    public:
        Person();
        Person(const char * const &, const char * const &, int const &);
        Person(Person const &);
        ~Person();

        Person &operator =(Person const &);

        int const &getAge() const;
        char const *getName() const;
        char const *getSurname() const;

    private:
        void free();
        void copy(Person const &);

        char *name, *surname;
        int age;

};