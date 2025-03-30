#include <iostream>
#include <cstring>
#include <utility>
#include <new>

class rule_of_five
{
    char *cstring; // raw pointer used as a handle to a dynamically-allocated memory block

    void copy(const char *s)
    {
        const size_t n = strlen(s) + 1;
        cstring = new(std::nothrow) char[n];                // allocate
        if (!cstring) return;
        strcpy(cstring, s);                                 // populate
    }

    void free()
    {
        delete[] cstring;
    }
public:
    rule_of_five(const char *s = "") : cstring(nullptr)
    {
        if (!s) return;
        copy(s);
    }

    ~rule_of_five()
    {
        free();                                             // deallocate
    }

    rule_of_five(const rule_of_five &other)                 // copy constructor
    {
        copy(other.cstring);
    }

    rule_of_five(rule_of_five &&other) noexcept             // move constructor
    {
        cstring = std::move(other.cstring);
        other.cstring = nullptr;
    }

    rule_of_five &operator =(const rule_of_five &other)      // copy assignment
    {
        if (this == &other) return *this;
        free();
        copy(other.cstring);
        return *this;
    }

    rule_of_five &operator =(rule_of_five &&other) noexcept  // move assignment
    {
        cstring = std::move(other.cstring);
        other.cstring = nullptr;
        return *this;
    }
};