#ifndef _VECTOR_H_
#define _VECTOR_H_
#include <cstddef>

class Vector {
public:
    // default constructor
    Vector(); 
    // constructor initializes the vector with a given capacity
    Vector(size_t capacity); 
    // constructor initializes the vector with a given size and fiils it with default values
    Vector(size_t size, int defaultValue);
    // destructor
    ~Vector();

    // clears the vector
    void Clear();
    // returns the value at the given index
    const int At(size_t index) const;
    // returns the value at the given index
    void SetAt(size_t index, int value);
    // adds a value to the end of the vector
    void PushBack(int value);

    // returns true if the vector is empty
    bool Empty() const;
    // returns the size of the vector
    size_t Size() const;
    // returns the capacity of the vector
    size_t Capacity() const;
private:
    // resizes the vector with a given factor
    void Resize(size_t factor = 2);

    size_t capacity = 0;
    size_t size = 0;
    int* data = nullptr;
};

#endif // _VECTOR_H_