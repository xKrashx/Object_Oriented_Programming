#include "MagicalBox.h"
#include <iostream>

MagicalBox::MagicalBox(const int* ptr,const size_t siz,const  size_t cap) {
	this->size = siz;
	this->capacity = cap;
	this->arr = new int[capacity];
}
void MagicalBox::free()noexcept {
	delete[]arr;
}
MagicalBox::~MagicalBox()noexcept {
	this->free();
}
void MagicalBox::copy(const MagicalBox& other) {
	
	this->size = other.size;
	this->capacity = other.capacity;
	this->arr = new int[this->size];
	for (size_t i = 0; i < this->size; ++i) {
		arr[i] = other.arr[i];
	}

}
MagicalBox::MagicalBox(const MagicalBox& other) {
	this->copy(other);
}
MagicalBox& MagicalBox::operator =(const MagicalBox& other) {
	if (this == &other) {
		return *this;
	}
	this->free();
	this->copy(other);
	return *this;
}

void MagicalBox::resize() {
	int *ptr1 = new int[this->capacity *= 2];
	for (size_t i = 0; i < this->size; ++i) {
		ptr1[i] = this->arr[i];
	}
	this->free();
	this->arr = ptr1;
}
void MagicalBox::insert(const int& newnum) {
	if (size == capacity)
		this->resize();
	this->arr[size++] = newnum;
}
int MagicalBox::pop()const {
	if (size == 0) {
		std::cout << "The box of the magician is empty!" << std::endl;
		return 0;
	}
	size_t index;
	int random_num = std::rand();
	index = random_num % this->size;//this way we take the remainder of divising to the size and all indeces are equally possible
	return this->arr[index];
}
