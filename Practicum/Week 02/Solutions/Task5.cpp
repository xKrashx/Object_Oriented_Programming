#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstring>
#include <new>

bool IsWordCharacter(char const ch){
    return 'a' <= ch && ch <= 'z' || 'A' <= ch && ch <= 'Z' || ch == '-';
}

void FreeWordsArray(char **words, size_t const size){

    for(size_t i = 0; i < size; ++i)
        delete[] words[i];
    delete[] words;

}

bool IsLexicographicallyBigger(char const *word1, char const *word2){

    while(*word1 == *word2){

        ++word1;
        ++word2;

    }

    return *word1 > *word2;

}

void SortWords(char **words, size_t const size){

    for(size_t i = 1; i < size; ++i){

        size_t j = 0;
        char *word = words[i];

        while(j < i && IsLexicographicallyBigger(words[i - j - 1], word)){

            words[i - j] = words[i - j - 1];
            ++j;

        }

        words[i - j] = word;

    }

}

size_t GetNumberOfWords(std::ifstream &ifs){

    size_t size = 0;
    bool startedWord = false;

    while(!ifs.eof()){

        char ch = ifs.get();
        if(!startedWord && IsWordCharacter(ch)) startedWord = true;
        else if(startedWord && !IsWordCharacter(ch)){
            
            ++size;
            startedWord = false;

        }

    }

    size += startedWord;

    return size;

}

int main(){

    std::ifstream ifs("../task4.txt");

    if(!ifs.is_open()){

        std::cout << "Could not open file.\n";
        return -1;

    }

    size_t size = GetNumberOfWords(ifs), totalNumberOfWords = 0;
    ifs.clear();
    ifs.seekg(0);

    char **words = new(std::nothrow) char *[size];
    if(!words){

        std::cout << "Memory error\n";
        ifs.close();
        return -1;

    }

    for(size_t i = 0;  i < size; ++i)
        words[i] = nullptr;

    size_t index = 0;
    size_t const DEFAULT_WORD_CAPACITY = 2;
    bool startedWord = false;
    size_t wordLength;

    while(!ifs.eof()){

        char ch = ifs.get();
        if(IsWordCharacter(ch)){

            if(startedWord) ++wordLength;
            else if(!startedWord){

                wordLength = DEFAULT_WORD_CAPACITY;
                startedWord = true;

            }


            char *temp = new(std::nothrow) char[wordLength];
            if(!temp){

                std::cout << "Memory error\n";
                ifs.close();
                FreeWordsArray(words, index);
                return -1;

            }

            if(words[index]){

                strcpy(temp, words[index]);
                delete[] words[index];

            }

            words[index] = temp;

            words[index][wordLength - 2] = ch;
            words[index][wordLength - 1] = '\0';

        }
        else if(startedWord){
            
            ++index;
            startedWord = false;

        }

    }

    ifs.close();

    SortWords(words, size);

    std::ofstream ofs("sorted.txt", std::ios::trunc);

    for(size_t i = 0; i < size; ++i)
        ofs << words[i] << '\n';

    FreeWordsArray(words, size);
    ofs.close();

    return 0;

}