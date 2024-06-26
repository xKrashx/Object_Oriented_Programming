#include "Geometric_vector.h"
Nvector::Nvector() {
	this->dimension = 0;
	this->coor_arr = nullptr;
}
Nvector::Nvector(size_t dim) {
	this->dimension = dim;
	this->coor_arr = new (std::nothrow) double[dimension];
	if (!coor_arr) {
		std::bad_alloc expr;
		throw expr;
	}
	for (size_t i = 0; i < dimension; ++i) {
		this->coor_arr[i] = 0;
	}
}
Nvector::Nvector(const Nvector& other) {
	dimension = other.dimension;
	coor_arr = new(std::nothrow)double[dimension];
	if (!coor_arr) {
		std::bad_alloc expr;
		throw expr;
	}
	for (size_t i = 0; i < dimension; ++i) {
		coor_arr[i] = other.coor_arr[i];
	}
}
Nvector::~Nvector() {
	delete[]this->coor_arr;
}
Nvector& Nvector::operator=(const Nvector& other) {
	
	if (this == &other) {
		return *this;
	}
	delete[]coor_arr;
	this->dimension = other.dimension;
	this->coor_arr = new(std::nothrow) double[dimension];
	if (!coor_arr) {
		std::bad_alloc expr;
		throw expr;
	}
	for (size_t i = 0; i < this->dimension; ++i) {
		this->coor_arr[i] = other.coor_arr[i];
	}
	return *this;
}


void Nvector::Setcoordinate(size_t index, double value) {
	this->coor_arr[index] = value;
}



size_t Nvector::GetDimension()const {
	return this->dimension;
}
bool Nvector::IsOperDefined(const Nvector& other)const {
	return (this->dimension == other.dimension);
}
double Nvector::scalarProduct(const Nvector& other)const {
	if (!IsOperDefined(other)) {
		return 1.0; //error value
	}
	double res = 0.0;
	for (size_t i = 0; i < this->dimension; ++i) {
		res += this->coor_arr[i] * other.coor_arr[i];
	}
	return res;
}

Nvector Nvector::operator +(const Nvector& other) {
	if (!IsOperDefined(other)) {
		Nvector nullvec;
		return nullvec;
	}
	Nvector res(dimension);
	for (size_t i = 0; i < res.dimension; ++i) {
		res.coor_arr[i] =this->coor_arr[i] + other.coor_arr[i];
		 }
	return res;
}
Nvector Nvector::operator-(const Nvector& other) {
	if (!IsOperDefined(other)) {
		Nvector nullvec;
		return nullvec;
	}
	Nvector res(dimension);
	for (size_t i = 0; i < this->dimension; ++i) {
		res.coor_arr[i] = this->coor_arr[i] - other.coor_arr[i];
	}
	return res;
}
Nvector& Nvector::operator*(const double& scalar) {
	for (size_t i = 0; i < this->dimension; ++i) {
		this->coor_arr[i] *= scalar;
	}
	return*this;
}
bool Nvector::operator||(const Nvector& other) {
	if (!IsOperDefined(other)) {
		return false;
	}
	double factor = this->coor_arr[0] / other.coor_arr[0];
	for (size_t i = 0; i < this->dimension; ++i) {
		if (!(abs(this->coor_arr[i] / other.coor_arr[i] - factor) < 0.0001)) {
			return false;
		}
	}
	return true;
}
double Nvector::operator--() {
	double vec_length =sqrt( scalarProduct(*this));
	return vec_length;
}
bool Nvector::operator|(const Nvector& other) { //Checks if the vectors are orthogonal
	if (abs(scalarProduct(other) - 0) < 0.0001) {
		return true;
	}
	else {
		return false;
	}
}
 std::ostream& operator <<(std::ostream& out, const Nvector& vector) {
	 out << "( ";
	 for (size_t i = 0; i < vector.dimension; ++i) {
		 out << vector.coor_arr[i] << " ";
	 }
	 out << ")";
	 return out;
}
 std::istream& operator >> (std::istream& in,  Nvector& vector) {
	 for (size_t i = 0; i < vector.dimension; ++i) {
		 in >> vector.coor_arr[i];
	 }
	 return in;
 }
 double& Nvector::operator[](const size_t& index)const {
	 return this->coor_arr[index];
 }
