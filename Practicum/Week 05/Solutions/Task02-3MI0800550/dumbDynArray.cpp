#include "dumbDynArray.hpp"

dumbDynArray::dumbDynArray(const char *str)
{

    for (size_t i = 0; i<=strlen(str); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            this->size++;
        }
    }

    this->numsInStr = new(std::nothrow) int[this->size];
    int index = 0;
    for (size_t i = 0 ; i < strlen(str); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            this->numsInStr[index] = str[i] - '0';
            index++;
        }
    }

    std::cout << this->numsInStr[1] << std::endl;
}

dumbDynArray::~dumbDynArray()
{
    delete[] numsInStr;
}
