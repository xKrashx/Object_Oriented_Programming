#pragma once

#include <cstddef>
#include <iostream>

class String{

    public:
        String() = default;
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
        size_t Length() const;
        void Clear();
        bool Empty() const;

    private:
        void Free();
        void Copy(String const &other);
        void Move(String &&other);
        void Resize(size_t const newCapacity);

        size_t const DEFAULT_CAPACITY = 16;
        size_t m_Capacity = DEFAULT_CAPACITY, m_Size = 0;
        char *m_Str = nullptr;

};