#include "Shape.hpp"
#include <stdexcept>
#include <utility>
#include <cmath>

Shape::Shape(size_t const numberOfPoints): m_NumberOfPoints(numberOfPoints){
	m_Points = new Point[numberOfPoints]; // [0,0], [0,0]....
}

Shape::Shape(Shape const &other){
	Copy(other);
}

Shape::Shape(Shape &&other) noexcept{
	Move(std::move(other));
}

Shape &Shape::operator =(Shape const &other){

	if(this == &other) return *this;

	Free();
	Copy(other);

	return *this;

}

Shape &Shape::operator =(Shape &&other) noexcept{

	if(this == &other) return *this;

	Free();
	Move(std::move(other));

	return *this;

}

Shape::~Shape() noexcept{
	Free();
}

void Shape::SetPoint(size_t pointIndex, int x, int y){

	if(pointIndex >= m_NumberOfPoints) throw std::out_of_range("Invalid Point index!");
	m_Points[pointIndex] = Point(x, y);

}

double Shape::Point::GetDistance(Point const other) const{

	int dx = x - other.x;
	int dy = y - other.y;

	return sqrt(dx * dx + dy * dy);

}

Shape::Point const Shape::GetPointAtIndex(size_t index) const{

	if(index >= m_NumberOfPoints) throw std::out_of_range("Invalid Point index!");
	return m_Points[index];

}

void Shape::Copy(Shape const &other){

	m_Points = new Point[other.m_NumberOfPoints];

	for(size_t i = 0; i < other.m_NumberOfPoints; ++i)
		m_Points[i] = other.m_Points[i];

	m_NumberOfPoints = other.m_NumberOfPoints;

}

void Shape::Move(Shape &&other) noexcept{

	m_Points = std::exchange(other.m_Points, nullptr);
	m_NumberOfPoints = other.m_NumberOfPoints;

}

void Shape::Free() noexcept{
	delete[] m_Points;
}