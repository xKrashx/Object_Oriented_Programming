#include <iostream>
#include <fstream>
#include <cstring>

const unsigned int NAME_SIZE = 8;
const unsigned int SIZE1 = 256;
const unsigned int SIZE2 = 512;
const unsigned int SIZE3 = 1024;

struct Student
{
	char name[24] = "";
	int fn = -1;

    Student(const char* name, const int fn) : fn(fn)
    {
        strcpy(this->name, name);
    }
};

int fillTheFile(const char* filename, unsigned int numberOfObjects)
{
    std::ofstream oFile(filename, std::ios::out | std::ios::binary);
    if(!oFile.is_open())
    {
        std::cout << "Error1";
        return -1;
    }

    int fn = 12345;
    for(unsigned i = 0; i < numberOfObjects; i++)
    {
        char name[NAME_SIZE] = "Name0i";

        if(i > 9)
        {
            name[4] = (i / 10) % 10;
            name[5] = i % 10;
        }
        else
        {
            name[5] = i;
        }

        Student si(name, fn);
        oFile.write((const char*)(&si), sizeof(si));

        fn++;
    }

    oFile.close();
    return 0;
}

int main()
{
    char fileName[] = "task6.bin";

    if(fillTheFile(fileName, 30) == -1)
    {
        return -1;
    }
    
    unsigned int size;
    do
    {
        std::cout << "size = ";
        std::cin >> size;
    } while(size != SIZE1 && size != SIZE2 && size != SIZE3);
    

    std::ifstream iFile("task6.bin", std::ios::in | std::ios::binary);
    if(!iFile.is_open())
    {
        std::cout << "Error2";
        return -1;
    }

    char* buffer = new(std::nothrow) char[size + 1];
    if(!buffer)
    {
        std::cout << "Memory problem!" << std::endl;
        iFile.close();
        return -1;
    }

    std::ofstream pi;
    unsigned int i = 0;

    while(!iFile.eof())
    {
        iFile.read(buffer, size);

        char name[NAME_SIZE] = "p0i.bin";
        if(i > 9)
        {
            name[1] = (i / 10) % 10;
            name[2] = i % 10;
        }
        else
        {
            name[2] = i;
        }

        pi.open(name, std::ios::out | std::ios::binary);
        if(!pi.is_open())
        {
            std::cout << "Error3";

            iFile.close();

            delete[] buffer;
            buffer = nullptr;

            return -1;
        }

        pi.write(buffer, size);
        pi.close();

        i++;
    }

    iFile.close();

    delete[] buffer;
    buffer = nullptr;

    return 0;
}
