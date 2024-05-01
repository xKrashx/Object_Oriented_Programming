#include "MagicalBox.hpp"

void MagicalBox::insert(const int new_el)
{
    this->elements.push_back(new_el);
    std::cout << this->elements.capacity() << std::endl;
}

void MagicalBox::pop()
{
    this->elements.pop_back();
}

int MagicalBox::PickElement()
{
    int rand = random(this->elements.size());
    return this->elements[rand];
}
