#ifndef __STRING_HPP_
#define __STRING_HPP_

#include <cstddef>
#include <iostream>

class String{

public:
    String();
    String(char const *str);
    String(String const &other);
    String(String &&other) noexcept;
    ~String() noexcept;

    String &operator =(String const &other);
    String &operator =(String &&other) noexcept;

    String &operator +=(String const &other);
    String &operator +=(char const *other);
    String &operator +=(char const other);

    String operator +(String const &other);
    String operator +(char const *other);
    String operator +(char const other);
    friend String operator +(char const *other, String const &obj);

    char &operator [](size_t const index);
    char const operator [](size_t const index) const;

    friend std::ostream &operator <<(std::ostream &os, String const &obj);
    friend std::istream &operator >>(std::istream &is, String &obj);

    bool operator >(String const &other) const;
    bool operator >(char const *other) const;
    friend bool operator >(char const *other, String const &obj);
    bool operator >=(String const &other) const;
    bool operator >=(char const *other) const;
    bool operator <(String const &other) const;
    bool operator <(char const *other) const;
    bool operator <=(String const &other) const;
    bool operator <=(char const *other) const;

    bool operator ==(String const &other) const;
    bool operator ==(char const *other) const;
    bool operator !=(String const &other) const;
    bool operator !=(char const *other) const;

    char const *c_str() const;
    size_t Capacity() const;
    size_t Length() const;
    bool Empty() const;
    void Clear();

private:
    bool IsSmallString() const;
    void SetIsSmallString();
    void SetIsNormalString();

private:
    void Resize(size_t const newCapacity);
    void Copy(String const &other);
    void Move(String &&other) noexcept;
    void Free() noexcept;

    static size_t const SMALL_STRING_CAPACITY = 3 * sizeof(char *);
    static size_t const BITS_IN_CHAR = 8;

    union{

        struct{

            char *m_Str;
            size_t m_Size, m_Capacity;

        };
        char m_Data[SMALL_STRING_CAPACITY];

    };

};

#endif