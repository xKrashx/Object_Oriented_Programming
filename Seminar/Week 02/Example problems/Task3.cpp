#include <iostream>
#include <cstddef>
#include <fstream>

size_t SizeOfFile(std::ifstream &f){

    size_t position = f.tellg();

    f.seekg(0, std::ios::end);
    size_t size = f.tellg();
    f.seekg(position);

    return size;

}

int main(){

    std::ifstream ifs("test.txt");
    std::cout << SizeOfFile(ifs) << '\n';
    return 0;

}