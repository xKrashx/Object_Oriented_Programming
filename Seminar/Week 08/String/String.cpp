#include "String.hpp"
#include <cstring>
#include <utility>

size_t FindClosestPowerOfTwo(size_t const m_Size){

    size_t pow = 1;
    while(pow < m_Size) pow <<= 1;
    return pow;

}

String::String(char const *str){

    m_Size = strlen(str);
    m_Capacity = FindClosestPowerOfTwo(m_Size + 1);
    this -> m_Str = new char[m_Capacity];
    strcpy(this -> m_Str, str);

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

    try{

        if(m_Size + other.m_Size + 1 > m_Capacity || !m_Str) Resize(FindClosestPowerOfTwo(m_Size + other.m_Size + 1));
        else if(!m_Str) Resize(m_Capacity);

    }
    catch(std::bad_alloc const &ex){

        std::cerr << ex.what() << '\n';
        return *this;

    }

    strcat(m_Str, other.m_Str);
    m_Size += other.m_Size;

    return *this;
    
}

String &String::operator +=(char const *other){

    size_t const length = strlen(other);

    try{

        if(m_Size + length + 1 > m_Capacity) Resize(FindClosestPowerOfTwo(m_Size + length + 1));
        else if(!m_Str) Resize(m_Capacity);

    }
    catch(std::bad_alloc const &ex){

        std::cerr << ex.what() << '\n';
        return *this;

    }

    strcat(m_Str, other);
    m_Size += length;

    return *this;

}

String &String::operator +=(char const other){

    try{

        if(m_Size + 2 > m_Capacity) Resize(FindClosestPowerOfTwo(m_Size + 2));
        else if(!m_Str) Resize(m_Capacity);

    }
    catch(std::bad_alloc const &ex){

        std::cerr << ex.what() << '\n';
        return *this;

    }

    m_Str[m_Size++] = other;
    m_Str[m_Size] = '\0';

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

    if(os.fail() || os.bad()) return os;
    return os << (obj.m_Str ? obj.m_Str : "");

}

std::istream &operator >>(std::istream &is, String &obj){

    if(is.fail() || is.bad()) return is;

    obj.Clear();

    char ch;

    while(ch = is.get()){

        if(ch == ' ' || ch == '\n') break;
        obj += ch;

    }

    return is;

}

bool String::operator >(String const &other) const{
    return strcmp(m_Str, other.m_Str) > 0;
}

bool String::operator >(char const *other) const{
    return strcmp(m_Str, other) > 0;
}

bool operator >(char const *other, String const &obj){
    return strcmp(other, obj.m_Str) > 0;
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

    if(index >= m_Size) throw std::out_of_range("Index out of range");
    return m_Str[index];

}

char const String::operator [](size_t const index) const{
    
    if(index >= m_Size) throw std::out_of_range("Index out of range");
    return m_Str[index];

}

char const *String::c_str() const{
    return m_Str;
}

size_t String::Length() const{
    return m_Size;
}

void String::Clear(){

    if(m_Str) *m_Str = '\0';
    m_Size = 0;

}

bool String::Empty() const{
    return !m_Size;
}

void String::Free(){
    delete[] m_Str;
}

void String::Copy(String const &other){

    m_Size = other.m_Size;
    m_Capacity = other.m_Capacity;
    m_Str = new char[other.m_Capacity];
    strcpy(m_Str, other.m_Str);

}

void String::Move(String &&other){

    m_Capacity = other.m_Capacity;
    m_Size = other.m_Size;
    m_Str = std::exchange(other.m_Str, nullptr);

}

void String::Resize(size_t const newCapacity){

    m_Capacity = newCapacity;

    char *temp = new char[newCapacity];
    if(m_Str) strcpy(temp, m_Str);

    Free();
    m_Str = temp;

}