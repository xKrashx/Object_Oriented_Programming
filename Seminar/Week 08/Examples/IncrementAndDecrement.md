```c++
struct X
{
    // prefix increment
    X &operator++()
    {
        // actual increment takes place here
        return *this; // return new value by reference
    }

    // postfix increment
    X operator++(int)
    {
        X old = *this; // copy old value
        operator++();  // prefix increment
        return old;    // return old value
    }

    // prefix decrement
    X &operator--()
    {
        // actual decrement takes place here
        return *this; // return new value by reference
    }

    // postfix decrement
    X operator--(int)
    {
        X old = *this; // copy old value
        operator--();  // prefix decrement
        return old;    // return old value
    }
};
```