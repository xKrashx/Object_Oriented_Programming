#include "String.hpp"
#include <stdexcept>
#include <cstring>
#include <utility>

size_t FindClosestPowerOfTwo(size_t const m_Size){

    size_t pow = 1;
    while(pow < m_Size) pow <<= 1;
    return pow;

}

String::String(){
    
    m_Str = nullptr;
    m_Capacity = 0;
    m_Size = 0;

    m_Data[SMALL_STRING_CAPACITY - 1] = SMALL_STRING_CAPACITY - 1;

}

String::String(char const *str): String(){

    size_t len = strlen(str);

    if(len < SMALL_STRING_CAPACITY){

        strcpy(m_Data, str);
        m_Data[SMALL_STRING_CAPACITY - 1] = SMALL_STRING_CAPACITY - len - 1;
        SetIsSmallString();

    }
    else{

        size_t capacity = FindClosestPowerOfTwo(len + 1);
        this -> m_Str = new char[capacity];
        m_Capacity = capacity;
        m_Size = len;
        strcpy(this -> m_Str, str);
        SetIsNormalString();

    }

}

String::String(String const &other){
    Copy(other);
}

String::String(String &&other) noexcept{
    Move(std::move(other));
}

String &String::operator =(String const &other){

    if(this == &other) return *this;

    *this = String(other);

    return *this;

}

String &String::operator =(String &&other) noexcept{

    if(this == &other) return *this;

    Free();
    Move(std::move(other));

    return *this;

}

String::~String() noexcept{
    Free();
}

String &String::operator +=(String const &other){

    if(Length() + other.Length() + 1 > Capacity()) Resize(FindClosestPowerOfTwo(Length() + other.Length() + 1));

    if(IsSmallString()){

        strcat(m_Data, other.c_str());
        m_Data[SMALL_STRING_CAPACITY - 1] -= other.Length();

    }
    else{
        
        strcat(m_Str, other.c_str());
        m_Size += other.Length();

    }

    return *this;
    
}

String &String::operator +=(char const *other){

    size_t const length = strlen(other);

    if(Length() + length + 1 > Capacity()) Resize(FindClosestPowerOfTwo(Length() + length + 1));

    if(IsSmallString()){

        strcat(m_Data, other);
        m_Data[SMALL_STRING_CAPACITY - 1] -= length;

    }
    else{

        strcat(m_Str, other);
        m_Size += length;

    }

    return *this;

}

String &String::operator +=(char const other){

    if(Length() + 2 > Capacity()) Resize(FindClosestPowerOfTwo(Length() + 2));

    if(IsSmallString()){

        m_Data[Length()] = other;
        m_Data[Length() + 1] = '\0';
        if(m_Data[SMALL_STRING_CAPACITY - 1]) --m_Data[SMALL_STRING_CAPACITY - 1];

    }
    else{

        m_Str[m_Size++] = other;
        m_Str[m_Size] = '\0';

    }

    return *this;

}

String String::operator +(String const &rhs){

    String result(*this);
    result += rhs;
    return result;

}

String String::operator +(char const *rhs){

    String result(*this);
    result += rhs;
    return result;

}

String String::operator +(char const rhs){

    String result(*this);
    result += rhs;
    return result;

}

String operator +(char const *lhs, String const &rhs){

    String result(lhs);
    result += rhs;
    return result;

}

std::ostream &operator <<(std::ostream &os, String const &obj){

    if(os.fail() || os.bad()) throw std::ios_base::failure("Stream is broken before performing this operation");
    return os << (obj.IsSmallString() ? obj.m_Data : obj.m_Str);

}

std::istream &operator >>(std::istream &is, String &obj){

    if(is.fail() || is.bad()) throw std::ios_base::failure("Stream is broken before performing this operation");

    obj.Clear();

    char ch;

    while(ch = is.get()){

        if(ch == ' ' || ch == '\n') break;
        obj += ch;

    }

    return is;

}

bool String::operator >(String const &other) const{
    return strcmp(c_str(), other.c_str()) > 0;
}

bool String::operator >(char const *other) const{
    return strcmp(c_str(), other) > 0;
}

bool operator >(char const *other, String const &obj){
    return strcmp(other, obj.c_str()) > 0;
}

bool String::operator >=(String const &other) const{
    return !(*this < other);
}

bool String::operator >=(char const *other) const{
    return !(*this < other);
}

bool String::operator <(String const &other) const{
    return other > *this;
}

bool String::operator <(char const *other) const{
    return other > *this;
}

bool String::operator <=(String const &other) const{
    return !(*this > other);
}

bool String::operator <=(char const *other) const{
    return !(*this > other);
}

bool String::operator ==(String const &other) const{
    return *this >= other && *this <= other;
}

bool String::operator ==(char const *other) const{
    return *this >= other && *this <= other;
}

bool String::operator !=(String const &other) const{
    return !(*this == other);
}

bool String::operator !=(char const *other) const{
    return !(*this == other);
}

char &String::operator [](size_t const index){

    if(index >= Length()) throw std::out_of_range("Index out of range");
    if(IsSmallString()) return m_Data[index];
    return m_Str[index];

}

char const String::operator [](size_t const index) const{

    if(index >= Length()) throw std::out_of_range("Index out of range");
    if(IsSmallString()) return m_Data[index];
    return m_Str[index];

}

char const *String::c_str() const{

    if(IsSmallString()) return m_Data;
    return m_Str;

}

size_t String::Capacity() const{

    if(IsSmallString()) return SMALL_STRING_CAPACITY;
    return m_Capacity & ~((size_t)1 << (sizeof(m_Capacity) * BITS_IN_CHAR - 1));

}

size_t String::Length() const{

    if(IsSmallString()) return Capacity() - m_Data[SMALL_STRING_CAPACITY - 1] - 1;
    return m_Size;

}

void String::Clear(){

    Free();
    m_Str = nullptr;
    m_Capacity = 0;
    m_Size = 0;
    SetIsSmallString();

}

bool String::Empty() const{
    return !m_Size;
}

bool String::IsSmallString() const{
    return !(((char *)&m_Capacity)[sizeof(m_Capacity) - 1] & 1 << (BITS_IN_CHAR - 1));
}

void String::SetIsSmallString(){
    ((char *)&m_Capacity)[sizeof(m_Capacity) - 1] &= ~(1 << (BITS_IN_CHAR - 1));
}

void String::SetIsNormalString(){
    ((char *)&m_Capacity)[sizeof(m_Capacity) - 1] |= 1 << (BITS_IN_CHAR - 1);
}

void String::Resize(size_t const newCapacity){

    char *temp = new char[newCapacity];

    if(IsSmallString()) strcpy(temp, m_Data);
    else strcpy(temp, m_Str);

    Free();

    m_Size = Length();
    m_Capacity = newCapacity;
    m_Str = temp;

    SetIsNormalString();

}

void String::Copy(String const &other){

    if(IsSmallString()){

        m_Str = other.m_Str;
        m_Size = other.m_Size;
        m_Capacity = other.m_Capacity;
        SetIsSmallString();

    }
    else{

        m_Str = new char[other.m_Capacity];
        m_Capacity = other.m_Capacity;
        m_Size = other.m_Size;
        strcpy(m_Str, other.m_Str);
        SetIsNormalString();

    }

}

void String::Move(String &&other) noexcept{

    m_Str = std::exchange(other.m_Str, nullptr);
    m_Capacity = other.m_Capacity;
    m_Size = other.m_Size;

}

void String::Free() noexcept{
    if(!IsSmallString()) delete[] m_Str;
}