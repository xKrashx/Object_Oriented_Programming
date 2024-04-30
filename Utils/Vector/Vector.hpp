#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cstddef>
#include <utility>
#include <stdexcept>
#include <type_traits>

template <typename T>
class Vector{

public:
    Vector() = default;
    explicit Vector(size_t capacity);
    Vector(size_t size, T const &defaultValue);
    Vector(Vector<T> const &other);
    Vector(Vector<T> &&other) noexcept;
    Vector& operator=(Vector<T> const &other);
    Vector& operator=(Vector<T> &&other) noexcept;
    ~Vector() noexcept;

public:
    T &operator [](size_t index);
    T const &operator [](size_t index) const;

public:
    void PushBack(T const &value);
    void PushBack(T &&value);
    template <typename... Args>
    std::enable_if_t<std::is_constructible<T, Args...>::value, void>
    EmplaceBack(Args&&... args);

    void PopBack();
    void PopFront();

    void Insert(size_t index, T const &value);
    void Clear();

public:
    bool Empty() const;
    size_t Size() const;
    size_t Capacity() const;

private:
    void Resize(size_t newCapacity);
    void Copy(Vector<T> const &other);
    void Move(Vector<T> &&other) noexcept;
    void Free() noexcept;

private:
    size_t m_Capacity = 0;
    size_t m_Size = 0;
    T *m_Data = nullptr;

};

size_t FindClosestPowerOfTwo(size_t const m_Size){

    size_t pow = 1;
    while(pow < m_Size) pow <<= 1;
    return pow;

}

template <typename T>
Vector<T>::Vector(size_t capacity){

    m_Data = new T[capacity];
    m_Capacity = capacity;

}

template <typename T>
Vector<T>::Vector(size_t size, T const &defaultValue){

    size_t capacity = FindClosestPowerOfTwo(size);
    m_Data = new T[capacity];
    m_Size = size;
    m_Capacity = capacity;
    for(size_t i = 0; i < size; ++i) m_Data[i] = defaultValue;

}

template <typename T>
Vector<T>::Vector(Vector<T> const &other){
    Copy(other);
}

template <typename T>
Vector<T>::Vector(Vector<T> &&other) noexcept{
    Move(std::move(other));
}

template <typename T>
Vector<T> &Vector<T>::operator =(Vector<T> const &other){

    if(this == &other) return *this;

    *this = Vector<T>(other);

    return *this;

}

template <typename T>
Vector<T> &Vector<T>::operator =(Vector<T> &&other) noexcept{

    if(this == &other) return *this;

    Free();
    Move(std::move(other));

    return *this;

}

template <typename T>
Vector<T>::~Vector() noexcept{
    Free();
}

template <typename T>
void Vector<T>::Clear(){

    delete[] m_Data;
    m_Data = nullptr;
    m_Size = 0;
    m_Capacity = 0;

}

template <typename T>
T &Vector<T>::operator [](size_t index){

    if(index >= m_Size) throw std::out_of_range("Index out of range");
    return m_Data[index];

}

template <typename T>
T const &Vector<T>::operator [](size_t index) const{

    if(index >= m_Size) throw std::out_of_range("Index out of range");
    return m_Data[index];

}

template <typename T>
void Vector<T>::PushBack(T const &value){

    if(m_Size == m_Capacity) Resize(m_Capacity *= 2);
    m_Data[m_Size++] = value;

}

template <typename T>
void Vector<T>::PushBack(T &&value){

    if(m_Size == m_Capacity) Resize(m_Capacity *= 2);
    m_Data[m_Size++] = std::move(value);

}

template <typename T>
template <typename... Args>
std::enable_if_t<std::is_constructible<T, Args...>::value, void>
Vector<T>::EmplaceBack(Args&&... args){
    PushBack(T(std::forward<Args>(args)...));
}

template <typename T>
void Vector<T>::PopBack(){

    if(Empty()) return;
    --m_Size;
    if(m_Size == m_Capacity / 4) Resize(m_Capacity /= 2);

}

template <typename T>
void Vector<T>::PopFront(){

    if(Empty()) return;
    for(size_t i = 0; i < m_Size - 1; ++i)
        m_Data[i] = m_Data[i + 1];
    --m_Size;
    if(m_Size == m_Capacity / 4) Resize(m_Capacity /= 2);

}

template <typename T>
void Vector<T>::Insert(size_t index, T const &value){

    if(index > m_Size) std::out_of_range("Index out of range");
    if(m_Size == m_Capacity) Resize(m_Capacity *= 2);

    for(size_t i = m_Size; i > index; --i)
        m_Data[i] = m_Data[i - 1];
    m_Data[index] = value;
    ++m_Size;

}

template <typename T>
bool Vector<T>::Empty() const{
    return !m_Size;
}

template <typename T>
size_t Vector<T>::Size() const{
    return m_Size;
}

template <typename T>
size_t Vector<T>::Capacity() const{
    return m_Capacity;
}

template <typename T>
void Vector<T>::Resize(size_t newCapacity){

    T *newData = new T[newCapacity];
    for(size_t i = 0; i < m_Size; ++i)
        newData[i] = m_Data[i];

    Free();

    m_Data = newData;
    m_Capacity = newCapacity;

}

template <typename T>
void Vector<T>::Copy(Vector<T> const &other){

    m_Data = new T[other.m_Capacity];
    m_Size = other.m_Size;
    m_Capacity = other.m_Capacity;
    for(size_t i = 0; i < other.m_Size; ++i) m_Data[i] = other.m_Data[i];

}

template <typename T>
void Vector<T>::Move(Vector<T> &&other) noexcept{

    m_Data = std::exchange(other.m_Data, nullptr);
    m_Size = other.m_Size;
    m_Capacity = other.m_Capacity;

}

template <typename T>
void Vector<T>::Free() noexcept{
    delete[] m_Data;
}

#endif // _VECTOR_H_