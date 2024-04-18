#include "Vector.hpp"

size_t NextPowerOfTwo(size_t x)
{
    if ((x != 0) && ((x & (x - 1)) == 0))
        return x;

    unsigned int count = 0;

    while (x != 0)
    {
        x >>= 1;
        count++;
    }

    return 1 << count;
}

bool IsPowerOfTwo(size_t x)
{
    return (x != 0) && ((x & (x - 1)) == 0);
}

Vector::Vector()
{
    this->cap = 1;
    this->vector = new int[this->cap];
}

Vector::Vector(const size_t cap)
{
    this->cap = cap;
    this->vector = new (std::nothrow) int[this->cap];
    if (this->vector == nullptr)
    {
        std::cout << "Error" << std::endl;
    }
}

Vector::Vector(const size_t cap, int num)
{
    if(!IsPowerOfTwo(cap)){
        this->cap = NextPowerOfTwo(cap);
    } else this->cap = cap;

    

    this->vector = new (std::nothrow) int[this->cap];
    if (this->vector == nullptr)
    {
        std::cout << "Error" << std::endl;
    }

    this->size = cap;
    std::fill(this->vector, this->vector + this->size, num);
}

Vector::~Vector()
{
    if (this->vector != nullptr)
    {
        delete[] this->vector;
    }
}

void Vector::PrintVector()
{
    std::cout << "<";
    for (size_t i = 0; i < this->cap - 1; i++)
    {
        std::cout << this->vector[i] << ", ";
    }
    std::cout << this->vector[this->cap - 1];
    std::cout << ">" << std::endl;
}

int Vector::operator[](const size_t pos)
{
    if (!(pos >= 0 && pos <= this->size))
    {
        std::cout << "No element in this position!" << std::endl;
    }

    return this->vector[pos];
}

int Vector::At(size_t pos)
{
    if (!(pos >= 0 && pos <= this->size))
    {
        std::cout << "No element in this position!" << std::endl;
    }

    return this->vector[pos];
}

void Vector::SetAt(size_t pos, int num)
{
    if (!(pos >= 0 && pos <= this->size))
    {
        std::cout << "Invalid position!" << std::endl;
    }

    this->vector[pos] = num;
}

void Vector::RemoveAt(size_t pos)
{
    if (!(pos >= 0 && pos <= this->size))
    {
        std::cout << "Invalid position!" << std::endl;
    }

    for (size_t i = pos; i < this->size; i++)
    {
        this->vector[i] = this->vector[i + 1];
    }
    this->size--;
}

void Vector::PushBack(int num)
{

    this->size++;

    if (this->size >= this->cap)
    {
        this->Resize(cap * 2);
    }

    this->vector[this->size - 1] = num;
}

void Vector::Resize(size_t new_size)
{
    if (new_size <= this->cap)
    {
        std::cout << "new size must be more than the last" << std::endl;
        return;
    }

    this->cap = new_size;
}

bool Vector::Empty()
{
    if (this->size == 0)
        return true;

    return false;
}

size_t Vector::Size()
{
    return this->size;
}

size_t Vector::Capacity()
{
    return this->cap;
}

std::ostream &operator<<(std::ostream &os, const Vector &v)
{
    os << "[";
    for (size_t i = 0; i < v.size; ++i)
    {
        os << v.vector[i];
        if (i < v.size - 1)
            os << ", ";
    }
    os << "]";
    return os;
}