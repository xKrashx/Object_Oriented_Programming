/*
    Rewrite the implementation of the class Flags so it is more memory efficient for the given value of MAX_FLAGS
	(without using any external container classes from the STL).
    Document any limitations this imposes on other possible MAX_FLAGS values.
*/

#include <iostream>
#include <random>

class Flags
{
public:
    // The only problem we will have is if the MAX_FLAGS value is not divisible by 8.
    static const int MAX_FLAGS = 32;

    Flags() { for (int i = 0; i < MAX_FLAGS / 8; ++i) m_flags[i] = false; }

    bool getFlag(int i)         { return m_flags[i / 8] & (1 << (i % 8)); } // We return the coresponding bit.
    void setFlag(int i, bool v) {
        if(m_flags[i / 8] & (1 << (i % 8))) m_flags[i / 8] &= (v << (i % 8)); // We check if the bit is 1 then we have to logical and (&).
        else m_flags[i / 8] |= (v << (i % 8));                                // Else the bit is 0 and we have to logical or (|).
    }
private:
    // Here we should use char, because it can be represented as a number and is not fixed to 0 and 1 only.
    // We devide by 8 because a char is 1byte = 8bits.
    // We want to use as little memory as possible.
    char m_flags[MAX_FLAGS / 8];
};


int main(int argc, char* argv[])
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> randIndex(0, Flags::MAX_FLAGS - 1);

    Flags flags;
    flags.setFlag(randIndex(rng), true);
    flags.setFlag(randIndex(rng), true);

    for (int i = 0; i < Flags::MAX_FLAGS; ++i)
    {
        std::cout << i << "->" << flags.getFlag(i) << std::endl;
    }

	return 0;
}