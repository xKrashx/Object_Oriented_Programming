#include "Beer.h"
#include <iostream>
Beer::Beer() {
	this->mark = nullptr;
	this->quantity = 0;
}
Beer::Beer(const char* nm, unsigned quant) {
	if (strlen(nm) >= MAX_NAME) {
		throw "Invalid name";
	}
	this->mark = new char[strlen(nm)+1];
	if (!mark) {
		throw "Bad allocation!";
	}
	strcpy_s(this->mark,strlen(nm)+1, nm);
	this->quantity = quant;
}
void Beer::Copy(const Beer& other) {
	this->mark = new char[strlen(other.mark) + 1];
	if (!mark) {
		throw "Bad allocation!";
	}
	strcpy_s(mark, strlen(other.Getmark()) + 1, other.Getmark());
	this->quantity = other.Getquantity();

}
Beer::Beer(const Beer& other) {
	this->Copy(other);
}

Beer& Beer::operator =(const Beer& other) {
	if (this == &other) {
		return *this;
	}
	this->Free();
	this->Copy(other);
	return *this;
}
void Beer::Free() {
	delete[]mark;
}
Beer::~Beer() {
	this->Free();
}
unsigned Beer::Getquantity()const {
	return this->quantity;
}
const char* Beer::Getmark()const {
	return this->mark;
}
void Beer::refill(Beer& other,const unsigned ref) {
	this->quantity += ref;
	other.Setquantity(other.Getquantity() - ref);
}
void Beer::Setquantity(unsigned newquant) {
	this->quantity = newquant;
}
void Beer::add(Beer& other, unsigned refill) {
	if (strlen(this->Getmark()) + strlen(other.Getmark()) + 2 > MAX_NAME)
		return;
	char* result = new char[strlen(this->Getmark()) + strlen(other.Getmark()) + 2];//+2 because of & and \0
	for (size_t i = 0; i < strlen(mark); ++i) {
		result[i] = mark[i];
	}
	result[strlen(mark)] = '&';
	for (size_t j = strlen(mark) + 1; j < strlen(this->Getmark()) + strlen(other.Getmark()) + 1; ++j) {
		result[j] = other.mark[j - (strlen(mark) + 1)];
	}
	result[strlen(this->Getmark()) + strlen(other.Getmark()) + 1] = '\0';
	this->Free();
	this->mark = new char[strlen(this->Getmark()) + strlen(other.Getmark()) + 2];
	strcpy_s(mark,strlen(result)+1, result);
	delete[]result;
	this->refill(other,refill);
}
bool Beer::check( const char* name_to_check) {
	bool is_found = false;
	bool is_found_here = true;
	size_t length = strlen(name_to_check);
	size_t begin_index = 0;
	while (begin_index + length <= strlen(mark)) {
		is_found_here = true;
		for (size_t i = 0; i < length; ++i) {
			if (mark[begin_index + i] != name_to_check[i]) {
				is_found_here = false;
				break;
			}
		}
		if (is_found_here) {
			is_found = true;
			break;
		}
		
		++begin_index;
	}
	return is_found;
	//return true;
}
