#include "Vector.hpp"
#include <new>
#include <iostream>

/**
 * @brief Default constructor. Initializes the vector with default values
*/
Vector::Vector() : capacity(0), size(0), data(nullptr) {}

/**
 * @brief Initializes the vector with a given capacity
 * 
 * @param capacity - the capacity of the vector
*/
Vector::Vector(size_t capacity) {
    // Allocate memory for the vector
    data = new(std::nothrow) int[capacity];
    // Check if the memory allocation was successful
    if (!data) {
        std::cout << "Memory allocation failed!" << std::endl;
        return;
    }
    // Set the capacity of the vector
    this->capacity = capacity;
}

/**
 * @brief Initializes the vector with a given size and fills it with default values
 * 
 * @param size - the size of the vector
 * @param defaultValue - the default value to fill the vector with
*/
Vector::Vector(size_t size, int defaultValue) {
    // Allocate memory for the vector
    data = new(std::nothrow) int[size];
    // Check if the memory allocation was successful
    if (!data) {
        std::cout << "Memory allocation failed!" << std::endl;
        return;
    }
    // Set the size of the vector (it will be filled with 'size' number of 'defaultValue's)
    this->size = size;
    // Set the capacity of the vector (it should be full here, so capacity = size)
    this->capacity = size;
    // Fill the vector with 'defaultValue's
    for (size_t i = 0; i < size; ++i) {
        data[i] = defaultValue;
    }
}

/**
 * @brief Destructor. 
*/
Vector::~Vector() {
    Clear();
}

/**
 * @brief Clears the data in the vector and sets data to default values 
*/
void Vector::Clear() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

/**
 * @brief Returns the value at the given index
 * 
 * @param index - the index of the value
 * @return const int - the value at the given index
*/
const int Vector::At(size_t index) const {
    if (index >= size) {
        std::cout << "Index out of bounds!" << std::endl;
        return -1;
    }
    return data[index];
}

/**
 * @brief Sets the value at the given index
 * 
 * @param index - the index of the value
 * @param value - the new value to set
*/
void Vector::SetAt(size_t index, int value) {
    if (index >= size) {
        std::cout << "Index out of bounds!" << std::endl;
        return;
    }
    data[index] = value;
}

/**
 * @brief Adds a value to the end of the vector
 * 
 * @param value - the new value to add
*/
void Vector::PushBack(int value) {
    // If the vector is full, resize it
    if (size == capacity) {
        Resize();
    }
    // Add the new value to the end of the vector and increment the size
    data[size++] = value;
}

/**
 * @brief Returns true if the vector is empty
 * 
 * @return bool - true if the vector is empty
*/
bool Vector::Empty() const {
    return size == 0;
}

/**
 * @brief Returns the size of the vector
 * 
 * @return size_t - the size of the vector
*/
size_t Vector::Size() const {
    return size;
}

/**
 * @brief Returns the capacity of the vector
 * 
 * @return size_t - the capacity of the vector
*/
size_t Vector::Capacity() const {
    return capacity;
}

/**
 * @brief Resizes the vector with a given factor
 * 
 * @param factor - the factor to resize the vector with
*/
void Vector::Resize(size_t factor) {
    if(factor == 0) return;
    size_t newCapacity = capacity > 0 ? capacity * factor : factor;
    // Allocate memory for the new vector
    int* newData = new(std::nothrow) int[newCapacity];
    // Check if the memory allocation was successful
    if (!newData) {
        std::cout << "Memory allocation failed!" << std::endl;
        return;
    }
    // Copy the data from the old vector to the new one
    for (size_t i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    // Delete the old data and set the new data
    delete[] data;
    data = newData;
    newData = nullptr;
    capacity = newCapacity;
}
