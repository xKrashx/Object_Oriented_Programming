/*
    Fix the problem with the class in the use case below.
    Write a comment about what methods are missing from the class definition if it needs to correctly handle all possible cases with optimal performance.
	Consider you're compiling in post C++11 when writing your answer.
*/

#include <iostream>
#include <random>

class FunArray
{
public:
    // Missing Default constructor.
    FunArray() = default; // No need to implement anything, because of the GenerateData method.
    // Missing Copy constructor.
    FunArray(FunArray const &other){

        m_DataSize = other.m_DataSize;
        m_Data = new uint8_t[other.m_DataSize];
        for(int i = 0; i < other.m_DataSize; ++i)
            ((uint8_t *)m_Data)[i] = ((uint8_t *)other.m_Data)[i];

    }
    // We might want to consider writing Move constructor.
    // We can not delete void *, so we need to cast it into the right type.
    ~FunArray() { delete[] (uint8_t *)m_Data; }
    // We might want to consider writing copy operator =.
    // We might want to consider writing move operator =.

    void GenerateData(int dataSize)
    {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<unsigned short> randData(std::numeric_limits<uint8_t>::min(), std::numeric_limits<uint8_t>::max());

        m_DataSize = dataSize;
        m_Data = new uint8_t[dataSize];
        for (int i = 0; i < dataSize; ++i)
            ((uint8_t *)m_Data)[i] = (uint8_t)randData(rng);
    }

    void Fun() { /* Do fun stuff */ }
private:
    // We will need to remeber how long is the array, so we can copy it.
    int m_DataSize;
    void* m_Data;
};

int main(int argc, char* argv[])
{
    FunArray a;
    a.GenerateData(42);
    a.Fun();

    // We need copy constructor here.
    FunArray* b = new FunArray(a);
    b->Fun();
    delete b;

	return 0;
}