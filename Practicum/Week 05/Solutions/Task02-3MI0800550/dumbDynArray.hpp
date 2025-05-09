#pragma once
#include <iostream>
#include <cstring>

class dumbDynArray
{
private:
    int* numsInStr;
    size_t size = 0;
public:
    dumbDynArray(const char* str);
    ~dumbDynArray();
};
