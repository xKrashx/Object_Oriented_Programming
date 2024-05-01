#include <vector>
#include <time.h>
#include <iostream>

class MagicalBox
{
public:

    void insert(const int new_el);
    void pop();

    int PickElement();

private:
    std::vector<int> elements;

    int random(int max)
    {
        srand(time(0));
        return rand() % max;
    }

};
