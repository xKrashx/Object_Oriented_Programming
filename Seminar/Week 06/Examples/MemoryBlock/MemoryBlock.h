#pragma once

#include <iostream>
#include <algorithm>

class MemoryBlock{

public:
    // Simple constructor that initializes the resource.
    explicit MemoryBlock(size_t length): mLength(length), mData(new int[length]){
        std::cout << "In MemoryBlock(size_t). length = " << mLength << ".\n";
    }

    // Destructor.
    ~MemoryBlock(){

        std::cout << "In ~MemoryBlock(). length = " << mLength << ".";

        if (mData != nullptr){

            std::cout << " Deleting resource.";
            free();

        }

        std::cout << '\n';

    }

    // Copy constructor.
    MemoryBlock(const MemoryBlock &other){

        std::cout << "In MemoryBlock(const MemoryBlock&). length = "
                << other.mLength << ". Copying resource.\n";
        copy(other);

    }

    // Copy assignment operator.
    MemoryBlock &operator =(const MemoryBlock &other){

        std::cout << "In operator=(const MemoryBlock&). length = "
                << other.mLength << ". Copying resource.\n";

        if (this == &other) return *this;

        free();
        copy(other);

        return *this;

    }

    // Move constructor.
    MemoryBlock(MemoryBlock &&other) noexcept{

        std::cout << "In MemoryBlock(MemoryBlock&&). length = "
                  << other.mLength << ". Moving resource.\n";

        // Copy the data pointer and its length from the
        // source object.
        mData = other.mData;
        mLength = other.mLength;

        // Release the data pointer from the source object so that
        // the destructor does not free the memory multiple times.
        other.mData = nullptr;
        other.mLength = 0;

    }

    // using std::move
    // MemoryBlock(MemoryBlock &&other) noexcept
    //     : mData(nullptr), mLength(0)
    // {
    //     *this = std::move(other);
    // }

    // Move assignment operator.
    MemoryBlock &operator =(MemoryBlock &&other) noexcept{

        std::cout << "In operator=(MemoryBlock&&). length = "
                  << other.mLength << ".\n";

        if(this == &other) return *this;

        free();

        // Copy the data pointer and its length from the
        // source object.
        mData = other.mData;
        mLength = other.mLength;

        // Release the data pointer from the source object so that
        // the destructor does not free the memory multiple times.
        other.mData = nullptr;
        other.mLength = 0;

        // Using std::move
        // *this = std::move(other);

        return *this;

    }

    // Retrieves the length of the data resource.
    size_t length() const{
        return mLength;
    }

private:
    void copy(MemoryBlock const &other){

        mLength = other.mLength;
        mData = new int[mLength];
        std::copy(other.mData, other.mData + mLength, mData);

    }

    void free(){

        // Free the existing resource.
        delete[] mData;
        mData = nullptr;
        mLength = 0;

    }

    size_t mLength = 0;     // The length of the resource.
    int *mData = nullptr;   // The resource.
};