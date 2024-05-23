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
    static const int MAX_FLAGS = 32;

    Flags() { for (int i = 0; i < MAX_FLAGS; ++i) m_flags[i] = false; }

    bool getFlag(int i)         { return m_flags[i]; }
    void setFlag(int i, bool v) { m_flags[i] = v; }
private:
    bool m_flags[MAX_FLAGS];
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