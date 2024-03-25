#pragma once
#include <iostream>

class Range
{
private:
    int a, b;
    bool is_union = false;

public:
    Range();
    Range(const int a, const int b);

    void SetA(const int a);
    void SetB(const int b);

    int Lenght();
    bool IsInRange(const int c);
    size_t NumOfPrimes();
    size_t NumOfPalindromes();
    size_t NumOfNonrepeating();

    bool PowerOfTwo();
    Range Intersect(const Range second);
    Range Union(const Range second);
    bool IsSubRange(const Range second);

    friend std::ostream &operator<<(std::ostream &out, const Range &range);

    ~Range(){};
};
