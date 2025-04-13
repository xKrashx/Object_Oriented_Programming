```c++
// copy assignment
T &operator=(const T &other)
{
    // Guard self assignment
    if (this == &other) {
        return *this;
    }

    // assume *this manages a reusable resource, such as a heap-allocated buffer mArray
    if (size != other.size)
    {                    // resource in *this cannot be reused
        delete[] mArray; // release resource in *this
        mArray = nullptr;
        size = 0;                     // preserve invariants in case next line throws
        mArray = new int[other.size]; // allocate resource in *this
        size = other.size;
    }

    std::copy(other.mArray, other.mArray + other.size, mArray);
    return *this;
}

// move assignment
T &operator=(T &&other) noexcept
{
    // Guard self assignment
    if (this == &other)
        return *this; // delete[]/size=0 would also be ok

    delete[] mArray;                               // release resource in *this
    mArray = std::exchange(other.mArray, nullptr); // leave other in valid state
    size = std::exchange(other.size, 0);
    return *this;
}
```