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
 * @brief Copy constructor. 
 * @details Initializes the vector with the data from another vector. This is a deep copy.
 * 
 * @param other - the vector to copy
*/
Vector::Vector(const Vector& other) {
    // Allocate memory for the vector
    data = new(std::nothrow) int[other.capacity];
    // Check if the memory allocation was successful
    if (!data) {
        std::cout << "Memory allocation failed!" << std::endl;
        return;
    }
    // Copy the size and capacity of the other vector to the current (this)
    size = other.size;
    // Copy the capacity from the other vector to the current (this)
    capacity = other.capacity;
    // Copy the data from the other vector to the current (this)
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

/**
 * @brief Copy assignment operator. 
 * @details Initializes the vector with the data from another vector. This is a deep copy.
 * 
 * @param other - the vector to copy
 * @return Vector& - the current vector
*/
Vector& Vector::operator=(const Vector& other) {
    // Check if the vectors are the same
    if (this != &other) {
        // Delete the current data
        delete[] data;
        // Allocate memory for the new data
        data = new(std::nothrow) int[other.capacity];
        if (!data) {
            std::cout << "Memory allocation failed!" << std::endl;
            return *this;
        }
        // Copy the size and capacity of the other vector to the current (this)
        size = other.size;
        // Copy the capacity from the other vector to the current (this)
        capacity = other.capacity;
        // Copy the data from the other vector to the current (this)
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    // Will return the current vector with copied data OR just the current vector if the vectors are the same
    return *this;
}

/**
 * @brief Move constructor. 
 * @details Moves the resources to the heap and reassigns the current Vector to point to them.
 * Prevents unnecessary copying.
 * 
 * @param other - the vector to move
*/
Vector::Vector(Vector&& other) {
    // Move the data from the other vector to the current (this)
    data = other.data;
    size = other.size;
    capacity = other.capacity;
    // Set the other vector's data to nullptr
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

/**
 * @brief Move assignment operator. 
 * @details Does the same as the move constructor, but also checks if the vectors are the same
 * Prevents uncessary operations if they are the same and just returns the current vector
 * 
 * @param other - the vector to move
 * @return Vector& - the current vector
*/
Vector& Vector::operator=(Vector&& other) {
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        capacity = other.capacity;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
    return *this;
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
 * @brief Removes the last element
*/
void Vector::PopBack() {
    if (Empty()) {
        std::cout << "Vector is empty!" << std::endl;
        return;
    }
    --size;
}

/**
 * @brief Removes the element at the given index and keeps the order of the elements
 * 
 * @param index - the index of the element to be removed
*/
void Vector::PopFront() {
    if (Empty()) {
        std::cout << "Vector is empty!" << std::endl;
        return;
    }
    // Shift all elements to the left to keep the order of the elements
    for (size_t i = 0; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

/**
 * @brief Inserts a value at the given index
 * 
 * @param index - the index to insert the value
 * @param value - the value to insert
*/
void Vector::Insert(size_t index, int value) {
    if (index > size) {
        std::cout << "Index out of bounds!" << std::endl;
        return;
    }
    // If the vector is full, resize it
    if (size == capacity) {
        Resize();
    }
    // Shift all elements to the right to make space for the new value
    for (size_t i = size; i > index; --i) {
        data[i] = data[i - 1];
    }
    // Insert the new value at the given index and increment the size
    data[index] = value;
    // Increment the size
    ++size;
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
