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
    ~FunArray() { delete[] m_Data; }

    void GenerateData(int dataSize)
    {
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<unsigned short> randData(std::numeric_limits<uint8_t>::min(), std::numeric_limits<uint8_t>::max());

        m_Data = new uint8_t[dataSize];
        for (int i = 0; i < dataSize; ++i)
            ((uint8_t *)m_Data)[i] = (uint8_t)randData(rng);
    }

    void Fun() { /* Do fun stuff */ }
private:
    void* m_Data;
};

int main(int argc, char* argv[])
{
    FunArray a;
    a.GenerateData(42);
    a.Fun();

    FunArray* b = new FunArray(a);
    b->Fun();
    delete b;

	return 0;
}