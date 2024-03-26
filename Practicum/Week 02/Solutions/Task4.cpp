#include <iostream>
#include <fstream>
#include <cstring>

bool found(char const * const word, char const * const line)
{
    unsigned int len = strlen(word);
    for(unsigned i = 0; i < len; i++)
    {
        if(line[i] != word[i])
        {
            return false;
        }
    }
    return true;
}

unsigned meetings(char const * const word, char const * const line)
{
    unsigned int len = strlen(line), count = 0;
    for(unsigned i = 0; i < len; i++)
    {
        if(line[i] == word[0] && found(word, line + i))
        {
            count++;
            i += strlen(word) - 1;
        }
    }
    return count;
}

int main()
{
    const unsigned int MAX_LEN = 256;

    char fileName[MAX_LEN];
    std::cout << "file name: ";
    std::cin >> fileName;

    std::ifstream file(fileName);
    if(!file.is_open())
    {
        std::cout << "File couldn`t be opened!" << std::endl;
        return 1;
    }

    char searchedWord[MAX_LEN];
    std::cout << "the searched word is: ";
    std::cin >> searchedWord;

    unsigned int lineIndex = 0;
    char line[MAX_LEN];

    while(!file.eof())
    {
        file.getline(line, MAX_LEN);

        unsigned int count = meetings(searchedWord, line);
        if(count > 0)
        {
            std::cout << '[' << lineIndex << "]: " << count << std::endl;
        }

        lineIndex++;
    }

    file.close();
    
    return 0;
}
