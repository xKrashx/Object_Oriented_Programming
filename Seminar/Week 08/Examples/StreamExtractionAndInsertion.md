```c++
std::ostream &operator<<(std::ostream &os, const T &obj)
{
    // write obj to stream
    return os;
}

std::istream &operator>>(std::istream &is, T &obj)
{
    // read obj from stream
    if (/* T could not be constructed */)
        is.setstate(std::ios::failbit);
    return is;
}