#include <iostream>
#include <fstream>


int main(){
    std::fstream file("text.txt",std::ios::out  | std::ios::in);
    size_t readCursor = file.tellg();
    size_t writeCursor = file.tellg();
    if(!file.is_open())return 0;
    while (!file.eof())
    {
        file.seekg(readCursor);
        char c = file.get();
        if(c != ' '){
            file.seekg(writeCursor);
            file<<c;
            writeCursor++;
        }
        readCursor++;
    
    }
    file.close();
    std::cout<<"done!";
    
    return 0;
}