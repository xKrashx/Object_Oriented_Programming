#include <iostream>
#include <fstream>
#include <cstring>

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

    char line[MAX_LEN];

    unsigned int currIndex = 0, 
                 minIndex = 0, maxIndex = 0,
                 minLen = UINT32_MAX, maxLen = 0; 
    
    while(!file.eof())
    {
        file.getline(line, MAX_LEN);
        unsigned int currLen = strlen(line);

        if(currLen > maxLen)
        {
            maxLen = currLen;
            maxIndex = currIndex;
        }

        if(currLen < minLen)
        {
            minLen = currLen;
            minIndex = currIndex;
        }

        currIndex++;
    }

    std::cout << "index of the shortest line: " << minIndex << std::endl;
    std::cout << "index of the longest line: " << maxIndex << std::endl;

    file.close();
    
    return 0;
}
