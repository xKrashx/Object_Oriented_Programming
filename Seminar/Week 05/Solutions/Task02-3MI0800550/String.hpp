#pragma once
#include <iostream>
#include <algorithm>

// TO DO : 
// Capacity + Size
// Combine memory fix

class String
{
private:
    char *string;
    size_t size;
public:
    String();
    String(size_t size);
    String(char* string);
    ~String(){delete[] string;};

    void print();
    friend std::ostream &operator<<(std::ostream& out , const String &str);
    void Copy(const String &str);
    void Append(const String &str);
    String Combine(String &str);
    const char* c_str();
    size_t Lenght();
    void Clear();
    bool Empty();
    char At(unsigned i);
    char operator[] (unsigned i);
};
