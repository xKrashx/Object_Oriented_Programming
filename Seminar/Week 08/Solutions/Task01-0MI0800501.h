#pragma once
#include <iostream>
#include <cmath>
class Nvector {
public:
	Nvector();
	Nvector(size_t dim);
	Nvector(const Nvector& other);
	~Nvector();
	size_t GetDimension() const;
	void Setcoordinate(size_t index, double value);
	
	bool IsOperDefined(const Nvector& other)const;
	
	Nvector& operator =(const Nvector& other);
	Nvector operator +(const Nvector& other);

	
	Nvector operator -(const Nvector& other);

	Nvector& operator *(const double& scalar);
	bool operator ||(const Nvector& other); //returns if the vectors are parallel
	double operator --();
	bool operator |(const Nvector& other); //returns if the vectors are perpendicular

	double& operator [](const size_t& index)const; //returns a coordinate of the vector

	friend std::ostream& operator <<(std::ostream& out, const Nvector& v);
	friend std::istream& operator >>(std::istream& in, Nvector& v);

	double scalarProduct(const Nvector& scl)const;

private:
	size_t dimension;
	double* coor_arr;
};
