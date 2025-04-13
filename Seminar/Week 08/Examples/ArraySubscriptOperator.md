If the value type is known to be a built - in type, the const variant should return by value.
Where direct access to the elements of the container is not wanted or
not possible or distinguishing between lvalue c[i] = v;
and rvalue v = c[i];
usage, operator[] may return a proxy.

```c++
struct T
{
    value_t &operator[](std::size_t idx) { return mVector[idx]; }
    const value_t &operator[](std::size_t idx) const { return mVector[idx]; }
};
```