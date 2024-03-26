#include <fstream>

void RemoveSpacesInFile(char const *fileName){

    std::ifstream ifs(fileName);

    if(!ifs.is_open()) return;

    std::ofstream ofs("result.txt");

    if(!ofs.is_open()) return;

    while(!ifs.eof()){

        char c = ifs.get();
        if(c != ' ') ofs << c;

    }


    ifs.close();
    ofs.close();

}

int main(){

    RemoveSpacesInFile("task2.txt");
    return 0;

}