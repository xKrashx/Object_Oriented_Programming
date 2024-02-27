#include <iostream>
#include <fstream>

int main(){

    std::ifstream ifs("test.txt");
    if(!ifs.is_open()) return -1;

    std::ofstream ofs("result.txt");
    if(!ofs.is_open()){

        ifs.close();
        return -1;

    }

    char from, to;
    std::cin >> from >> to;

    while(!ifs.eof()){

        char c = ifs.get();
        if(c == from) c = to;
        ofs << c;

    }

    ifs.close();
    ofs.close();

    return 0;

}