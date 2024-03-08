#include <iostream>
#include <cstddef>

union Color{

    uint32_t hexValue;

    struct{

        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;

    };

};

char *ToHex(uint32_t const value){

    size_t const prefixSize = 2;
    size_t const bitsInAByte = 8;
    char *str = new(std::nothrow) char[prefixSize + sizeof(value) * 2 + 1];

    if(!str) return nullptr;

    size_t index = 0;
    str[index++] = '0';
    str[index++] = 'x';

    for(size_t i = 0; i < sizeof(value); ++i){

        uint8_t byteValue = value >> (i * bitsInAByte) & UINT8_MAX;
        uint8_t firstNibble = byteValue >> (bitsInAByte / 2) & 0b1111;
        uint8_t secondNibble = byteValue & 0b1111;

        str[index++] = (firstNibble < 10 ? '0' : 'A') + (firstNibble % 10);
        str[index++] = (secondNibble < 10 ? '0' : 'A') + (secondNibble % 10);

    }

    str[index] = '\0';

    return str;

}

void PrintColor(Color const c){

    char *hexValue = ToHex(c.hexValue);

    if(!hexValue){

        std::cout << "Memory error\n";
        return;

    }

    std::cout << (uint32_t)c.r << ' ' << (uint32_t)c.g << ' ' << (uint32_t)c.b << ' ' << ((double)c.a) / UINT8_MAX << ' ' << hexValue;

    delete[] hexValue;

}

int main(){

    Color c;
    uint32_t red, green, blue;
    double alpha;

    std::cin >> red >> green >> blue >> alpha;

    c.r = red;
    c.g = green;
    c.b = blue;
    c.a = alpha * UINT8_MAX;

    PrintColor(c);

    return 0;

}