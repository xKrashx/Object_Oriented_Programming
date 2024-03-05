#include "test.hpp"
#include <iostream>

extern "C"{
    DLLExport void func(){
        std::cout << "Here\n";
    }
}