#pragma once
class Todo {
public:
	Todo();
	Todo(const bool ind, const char* des, const unsigned int id);
	~Todo()noexcept;
	Todo(const Todo& other);
	Todo& operator =(const Todo& other);
	Todo(Todo&& other)noexcept;
	Todo& operator =(Todo&& other)noexcept;
	void printtask()const;
	void Fulfill();
private:
	bool indicator;
	//size_t size;
	char* description;
	unsigned int id;
	void free()noexcept;
	void copy(const Todo& other);
	void move(Todo&& other)noexcept;
};
