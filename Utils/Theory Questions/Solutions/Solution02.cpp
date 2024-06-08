/*
    Extend class A in such a way that dynamically allocated instances will be placed inside the memory occupied by g_classPool.
    Assume instances will be freed in order opposite of the order of creation.

    Write a comment documenting what needs to be added if we want to allocate arrays as well as individual objects.
    Write a comment explaining what needs to be added to the program so that all dynamic allocation uses memory from g_classPool.
*/

#include <iostream>

char g_classPool[1024];
int g_classPoolFreeOffset = 0;

// This is the universal way to allocate and deallocate memory for each call of new and delete respectfully.
void *operator new(size_t size){

    g_classPoolFreeOffset += size;
    return static_cast<void *>(&g_classPool[g_classPoolFreeOffset - size]);

}

void operator delete(void *ptr, size_t size) noexcept{
    g_classPoolFreeOffset -= size;
}

// New and delete for arrays.
void *operator new[](size_t size){

    g_classPoolFreeOffset += size;
    return static_cast<void *>(&g_classPool[g_classPoolFreeOffset - size]);    

}

void operator delete[](void *ptr, size_t size) noexcept{
    g_classPoolFreeOffset -= size;
}

class A
{
public:
    A(): m_data(42) {}
    ~A() {}

    // These are the operators new and delete that will be specifically used for allocations of type A.
    void *operator new(size_t size){

        g_classPoolFreeOffset += size;
        return static_cast<void *>(&g_classPool[g_classPoolFreeOffset - size]);

    }

    void operator delete(void *ptr, size_t size) noexcept{
        g_classPoolFreeOffset -= size;
    }

    // New and delete for arrays.
    void *operator new[](size_t size){

        g_classPoolFreeOffset += size;
        return static_cast<void *>(&g_classPool[g_classPoolFreeOffset - size]);

    }

    void operator delete[](void *ptr, size_t size) noexcept{
        g_classPoolFreeOffset -= size;
    }

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