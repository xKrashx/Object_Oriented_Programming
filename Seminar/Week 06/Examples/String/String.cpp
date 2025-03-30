#include "String.hpp"
#include <cstring>
#include <utility>
#include <new>

size_t FindClosestPowerOfTwo(size_t const size){

    size_t pow = 1;
    while(pow < size) pow <<= 1;
    return pow;

}

String::String(){

    str = new(std::nothrow) char[capacity];
    if(str) *str = '\0';

}

String::String(char const * const str){

    size = strlen(str);
    capacity = FindClosestPowerOfTwo(size + 1);
    this -> str = new(std::nothrow) char[capacity];
    if(this -> str) strcpy(this -> str, str);

}

String::String(String const &other){
    copy(other);
}

String::String(String &&other){
    move(std::move(other));
}

String &String::operator =(String const &other){

    if(this == &other) return *this;

    free();
    copy(other);

    return *this;

}

String &String::operator =(String &&other){

    if(this == &other) return *this;

    free();
    move(std::move(other));

    return *this;

}

String::~String(){
    free();
}

char const *String::c_str() const{
    return str;
}
size_t String::Length() const{
    return size;
}

void String::Append(char const *str){

    if(!str) return;
    size_t length = strlen(str);
    if(size + length + 1 > capacity) resize(2 * capacity);
    if(this -> str) strcat(this -> str, str);

}

void String::Append(String const &other){

    if(size + other.size + 1 > capacity) resize(2 * capacity);
    if(str) strcat(str, other.str);

}

String String::Combine(String const &other) const{

    String result(*this);
    result.Append(other);
    return result;

}

void String::Clear(){

    resize(DEFAULT_CAPACITY);
    if(!str) return;
    *str = '\0';
    size = 0;

}

bool String::Empty() const{
    return !size;
}

char String::At(size_t const index) const{
    return str[index];
}

void String::free(){
    delete[] str;
}

void String::copy(String const &other){

    size = other.size;
    capacity = other.capacity;
    str = new(std::nothrow) char[other.capacity];
    if(str) strcpy(str, other.str);

}

void String::move(String &&other){

    capacity = std::exchange(other.capacity, 0);
    size = std::exchange(other.size, 0);
    str = std::exchange(other.str, nullptr);

}

void String::resize(size_t const newCapacity){

    capacity = newCapacity;
    char *temp = new(std::nothrow) char[newCapacity];
    if(!temp) return;

    for(size_t i = 0; i < size; ++i)
        temp[i] = str[i];

    free();
    str = temp;

}