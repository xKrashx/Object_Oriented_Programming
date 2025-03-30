#include <iostream>

// A class that contains a memory resource.
class MemoryBlock
{
    // TODO: Add resources for the class here.
};

void g(const MemoryBlock &)
{
    std::cout << "In g(const MemoryBlock&)." << std::endl;
}

void g(MemoryBlock &&)
{
    std::cout << "In g(MemoryBlock&&)." << std::endl;
}

MemoryBlock &&f(MemoryBlock &&block)
{
    g(block);
    return std::move(block);
}

int main()
{
    g(f(MemoryBlock()));
}