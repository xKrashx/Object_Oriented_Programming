#include "DumbDynArray.hpp"

#include <iostream>
#include <cassert>
#include <new>

DumbDynArray::DumbDynArray(const char* str) 
    : array(nullptr), size(0)
{
    if(!str)
    {
        std::cout << "Invalid string!" << std::endl;
        return;
    }

    unsigned short count = CountDigits(str);

    this->array = new(std::nothrow) unsigned short[count];
    if(!this->array)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }

    unsigned short i = 0, k = 0;

    while(str[i] != '\0')
    {
        if(IsDigit(str[i]))
        {
            this->array[k++] = str[i] - '0';
            this->size++;
        }
        i++;
    }

    assert(this->size == count);
}

DumbDynArray::~DumbDynArray()
{
    delete[] this->array;
    this->array = nullptr;
}

void DumbDynArray::Print() const
{
    for(unsigned i = 0; i < this->size; i++)
    {
        std::cout << this->array[i] << ' ';
    }
    std::cout << std::endl;
}

bool DumbDynArray::IsDigit(char c) const
{
    return c >= '0' && c <= '9';
}

unsigned short DumbDynArray::CountDigits(const char* str) const
{
    unsigned short i = 0, count = 0;
    while(str[i] != '\0')
    {
        if(IsDigit(str[i++]))
        {
            count++;
        }
    }
    return count;
}
