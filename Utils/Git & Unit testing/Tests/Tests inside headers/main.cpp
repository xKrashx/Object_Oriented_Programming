#define FACT_WITH_TESTS
#include "fact.hpp"
#include <iostream>

#ifdef DOCTEST_CONFIG_IMPLEMENT
#define test doctest::Context().run()
#else
#define test
#endif

using std::cout;

int main(){

    test;
    cout << fact(10) << '\n';
    
}