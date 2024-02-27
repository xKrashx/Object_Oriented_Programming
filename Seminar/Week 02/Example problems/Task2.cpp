#include <iostream>
#include <fstream>

void CopyFile(char const *from, char const *to){

    std::ifstream ifs(from);
    if(!ifs.is_open()) return;

    std::ofstream ofs(to, std::ios::trunc);
    if(!ofs.is_open()){

        ifs.close();
        return;

    }

    while(!ifs.eof()){

        char c = ifs.get();
        ofs << c;

    }

    ifs.close();
    ofs.close();

}

int main(){

    CopyFile("test.cpp", "otherTest.cpp");
    return 0;

}