#include <iostream>
#include <cstdint>
#include <cstddef>
#include <chrono>
#include <string>

// Disable padding
#pragma pack(push, 1)
struct no_padding{

    int16_t a = 1;
    int32_t b = 2;
    int16_t c = 3;

}/*__attribute__((packed))*/; // Another way to disable
#pragma pack(pop)

struct with_padding{

    int16_t a;
    int32_t b;
    int16_t c;

};

int main(){

    std::cout << sizeof(no_padding) << '\n';
    std::cout << sizeof(with_padding) << '\n';
    
    std::size_t const SIZE = 100'000;

    {

        auto start = std::chrono::steady_clock::now();

        with_padding array[SIZE];
        for(std::size_t i = 0; i < SIZE; ++i){

            array[i].a = 1;
            array[i].b = 2;
            array[i].c = 3;

        }

        auto end = std::chrono::steady_clock::now();
        auto diffGlobal = end - start;

        std::cout << '\n' << std::string(23, '=') << "\nCode ran for: " << std::chrono::duration<double, std::ratio<1, 1>>(diffGlobal).count() << "s\n";

    }

    {

        auto start = std::chrono::steady_clock::now();

        no_padding array[SIZE];
        for(std::size_t i = 0; i < SIZE; ++i){

            array[i].a = 1;
            array[i].b = 2;
            array[i].c = 3;

        }
        
        auto end = std::chrono::steady_clock::now();
        auto diffGlobal = end - start;

        std::cout << '\n' << std::string(23, '=') << "\nCode ran for: " << std::chrono::duration<double, std::ratio<1, 1>>(diffGlobal).count() << "s\n";

    }

}