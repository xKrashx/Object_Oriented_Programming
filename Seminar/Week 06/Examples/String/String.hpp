#pragma once

#include <cstddef>

class String{

    public:
        String();
        String(char const *str);
        String(String const &other);
        String(String &&other);
        ~String();

        String &operator =(String const &other);
        String &operator =(String &&other);

        char const *c_str() const;
        size_t Length() const;
        void Append(char const *str);
        void Append(String const &other);
        String Combine(String const &other) const;
        void Clear();
        bool Empty() const;
        char At(size_t const index) const;

    private:
        void free();
        void copy(String const &other);
        void move(String &&other);
        void resize(size_t const newCapacity);

        size_t const DEFAULT_CAPACITY = 16;
        size_t capacity = DEFAULT_CAPACITY, size = 0;
        char *str = nullptr;

};