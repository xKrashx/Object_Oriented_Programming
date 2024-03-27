#include <iostream>
#include <time.h>

int main(){

    srand(time(0)); // Слагаме seed-а на random да е времето. (стандартна практика)

    for(size_t i = 0; i < 10; ++i)
        std::cout << rand() % 100 << '\n'; // % 100 -> число в интервалът [0, 100).

}