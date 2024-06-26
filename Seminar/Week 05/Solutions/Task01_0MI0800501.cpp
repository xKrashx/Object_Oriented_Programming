#include "String.h"
#include <iostream>
String::String() {
	this->capacity = 16;
	this->ch = new(std::nothrow) char[capacity+1];
	if (!ch) {
		std::cout << "Memory error!" << std::endl;
		return;
	}
	//ch[0] = '\0';
}
String::String(size_t size) {
	this->capacity = size;
	this->ch = new(std::nothrow) char[capacity+1];
	if (!ch) {
		std::cout << "Memory error!" << std::endl;
		return;
	}
	//ch[0] = '\0';


}
String::String(const String& other) {
	this->capacity = other.capacity;
	this->ch = new(std::nothrow) char[capacity+1];
	if (!ch) {
		std::cout << "Memory error!" << std::endl;
		return;
	}
	for (size_t i = 0; i < capacity; ++i) {
		ch[i] = other.ch[i];
	}
}
String::~String() {
	//std::cout << "String destroyed!" << std::endl;
	delete[]ch;
}
unsigned int String::Length()const  {
	unsigned int n=0;
	size_t i = 0;
	while (ch[i] != '\0') {
		++i;
		++n;
	}
	return n;
}
void String::Clear() {
	delete[]ch;
	ch = new(std::nothrow) char[1];
	if (!ch) {
		std::cout << "Memory error!" << std::endl;
		return;
	}
	ch[0] = '\0';
}
bool String::Empty()const {
	if (ch[0] == '\0')
		return true;

	return false;
}
char String::At(const size_t i) const {
	if (i > capacity) {
		return '\0';
	}
	return ch[i-1];
}
 char*const  String::c_str()const{
	return this->ch;
}
 void String::Append(const String &other) {
	 unsigned int N = other.Length() + this->Length() + 1;
	 char* result = new(std::nothrow) char[N];
	 if (!result) {
		 std::cout << "Memory error!" << std::endl;
		 return;
	 }
	 for (size_t j = 0; j < N-1; ++j) {
		 if(j<this->Length())
		 result[j] = ch[j];
		 else {
			 result[j] = other.ch[j-this->Length()];
		 }
	 }
	 result[N-1] = '\0';
	 delete[]ch;
	 ch = result;
	// delete result;

 }
 String String::Combine(const String& other) {
	 String s;
	 unsigned int N = other.Length() + this->Length() + 1;
	 s.ch = new(std::nothrow) char[N];
	 if (!s.ch) {
		 std::cout << "Memory error!" << std::endl;
		// return;
	 }
	 for (size_t j = 0; j < N - 1; ++j) {
		 if (j < this->Length())
			 s.ch[j] = ch[j];
		 else {
			 s.ch[j] = other.ch[j - this->Length()];
		 }
	 }
	 s.ch[N-1] = '\0';
	 s.capacity = N;
	 return s;
