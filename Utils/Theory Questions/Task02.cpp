/*
    Extend class A in such a way that dynamically allocated instances will be placed inside the memory occupied by g_classPool.
    Assume instances will be freed in order opposite of the order of creation.

    Write a comment documenting what needs to be added if we want to allocate arrays as well as individual objects.
    Write a comment explaining what needs to be added to the program so that all dynamic allocation uses memory from g_classPool.
*/

#include <iostream>

char g_classPool[1024];
int g_classPoolFreeOffset = 0;

class A
{
public:
    A(): m_data(42) {}
    ~A() {}

    int getData() { return m_data; }
private:
    int m_data;
};

int main(int argc, char* argv[])
{
    A* obj = new A();
    int *pi = new int(5);

    std::cout << obj->getData() << std::endl;
    std::cout << *pi << std::endl;

    delete pi;
    delete obj;

	return 0;
}