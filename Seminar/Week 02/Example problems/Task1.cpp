#include <iostream>
#include <fstream>

void PrintCurrentFile(){

    std::ifstream ifs("test.cpp");

    if(!ifs.is_open()) return;

    while(!ifs.eof()){

        char c = ifs.get();

        std::cout << c;

    }

    ifs.close();

}

int main(){

    PrintCurrentFile();
    return 0;

}