#include "ToDo.h"
#include <iostream>
Todo::Todo() {
	this->indicator = false;
	this->id = 1;
	this->description = new char[1];
	description[0] = ' ';
}
void Todo::free()noexcept {
	delete[]description;
}
Todo::~Todo()noexcept {
	this->free();
}
Todo::Todo(const bool ind, const char* des, const unsigned int id) {
	this->indicator = ind;
	
	this->id = id;
	this->description = new char[strlen(des)+1];
	strcpy_s(this->description,strlen(des)+1, des);
}
Todo::Todo(const Todo& other) {
	this->copy(other);
}

Todo& Todo::operator =(const Todo& other) {
	if (this == &other)
		return *this;
	*this = Todo(other);
	return *this;
}

void Todo::copy(const Todo& other) {
	this->indicator = other.indicator;
	this->id = other.id;
	this->description = new char[strlen(other.description) + 1];
	strcpy_s(this->description, strlen(other.description)+1, other.description);
}
void Todo::move(Todo&& other)noexcept {
	this->indicator = other.indicator;
	this->id = other.id;
	this->description=std::exchange(other.description, nullptr);
}
Todo& Todo::operator =(Todo&& other)noexcept {
	if (this == &other)
		return *this;
	this->free();
	this->move(std::move(other));
	return *this;
}
Todo::Todo(Todo&& other)noexcept {
	this->move(std::move(other));
}
void Todo::Fulfill() {
	this->indicator = true;
	char another_des[] = "Task complete!";
	this->free();
	this->description = new char[strlen(another_des) + 1];
	strcpy_s(this->description, strlen(another_des)+1, another_des);
}
void Todo::printtask()const {
	std::cout << this->description << '\n';
}
