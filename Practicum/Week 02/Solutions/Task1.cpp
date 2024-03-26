#include <iostream>
#include <fstream>
#include <cstddef>

bool IsWordCharacter(char const ch){
    return 'a' <= ch && ch <= 'z'
        || 'A' <= ch && ch <= 'Z'
        || '0' <= ch && ch <= '9'
        || ch == '-';
}

size_t CountWordsInFile(std::ifstream &ifs){

    size_t initialPosition = ifs.tellg();

    ifs.seekg(0);

    bool startedWord = false;
    size_t count = 0;

    while(!ifs.eof()){

        char c = ifs.get();
        if(!startedWord && IsWordCharacter(c)) startedWord = true;
        else if(startedWord && !IsWordCharacter(c)){

            ++count;
            startedWord = false;

        }

    }

    count += startedWord;

    ifs.seekg(initialPosition);

    return count;

}

int main(){

    std::ifstream ifs("task1.txt");

    if(!ifs.is_open()){

        std::cout << "Couldn't open file\n";
        return 0;

    }

    std::cout << CountWordsInFile(ifs) << '\n';

    ifs.close();

    return 0;

}