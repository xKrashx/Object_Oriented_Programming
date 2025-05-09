#include <iostream>
#include <algorithm>

class Vector
{
private:
    int* vector;
    size_t size = 0;
    size_t cap = 1;
public:
    Vector();
    Vector(const size_t size);
    Vector(const size_t size, int num);
    ~Vector();

    void Resize(size_t new_size);
    int At(size_t pos); 
    void SetAt(size_t pos, int num);
    void RemoveAt(size_t pos);
    void PushBack(int num); 
    bool Empty();
    size_t Size();
    size_t Capacity();

    void PrintVector();

    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
    int operator[](const size_t pos);

};


