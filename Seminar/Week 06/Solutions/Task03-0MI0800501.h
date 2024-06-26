#pragma once
class MagicalBox {
public:
	MagicalBox() :size(0), capacity(10), arr(new int[capacity]) {}
	MagicalBox(const int* ptr,const size_t siz, const size_t cap);
	~MagicalBox()noexcept;
	MagicalBox(const MagicalBox& other);
	MagicalBox& operator =(const MagicalBox& other);
	void insert(const int& newnum);
	int pop()const;
private:
	size_t size;
	size_t capacity;
	int* arr;
	void resize();
	void free()noexcept;
	void copy(const MagicalBox& other);
	
};
