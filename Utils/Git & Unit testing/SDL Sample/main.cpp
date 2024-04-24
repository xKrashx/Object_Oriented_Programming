#include <stdexcept>
#include <iostream>
#include "App.hpp"
// Can't be bothered to search why it overrides WinMain as entry point.
// So just undef it and it works as it should normally.
#undef main

int main(){

    try{
        App theApp;
        theApp.Execute();
    }
    catch(std::logic_error const &ex){
        std::cerr << ex.what() << '\n';
    }

    return 0;

}