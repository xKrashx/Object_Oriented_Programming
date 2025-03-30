#include <iostream>
#include <cstddef>
#include <cstring>
#include <new>

// If a class requires a user-defined destructor, a user-defined copy constructor,
// or a user-defined copy assignment operator, it almost certainly requires all three.

class rule_of_three
{
    char *cstring; // raw pointer used as a handle to a dynamically-allocated memory block

    void copy(const char *s, size_t n)
    {
        if (!s) return;
        cstring = new(std::nothrow) char[n];                // allocate
        if (!cstring) return;
        strcpy(cstring, s);                                 // populate
    }

    rule_of_three(const char *s, size_t n)                  // to avoid counting twice
    {
        copy(s, n);
    }

public:
    rule_of_three(const char *s = "")
        : rule_of_three(s, std::strlen(s) + 1) {}

    ~rule_of_three()                                        // I. destructor
    {
        delete[] cstring;                                   // deallocate
    }

    rule_of_three(const rule_of_three &other)               // II. copy constructor
        : rule_of_three(other.cstring)
    {
    }

    rule_of_three &operator=(const rule_of_three &other)    // III. copy assignment
    {
        if (this == &other) return *this;

        delete[] cstring;
        copy(other.cstring, strlen(other.cstring));

        return *this;
    }
};