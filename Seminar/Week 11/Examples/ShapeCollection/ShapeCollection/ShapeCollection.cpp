#include "ShapeCollection.hpp"
#include <stdexcept>
#include <utility>

ShapeCollection::ShapeCollection(): m_Capacity(4), m_Size(0), m_Shapes(new Shape *[m_Capacity]){}

ShapeCollection::ShapeCollection(ShapeCollection const &other){
	Copy(other);
}

ShapeCollection::ShapeCollection(ShapeCollection &&other) noexcept{
	Move(std::move(other));
}

ShapeCollection &ShapeCollection::operator =(ShapeCollection const &other){

	if(this == &other) return *this;

	*this = ShapeCollection(other);

	return *this;

}

ShapeCollection &ShapeCollection::operator =(ShapeCollection &&other) noexcept{

	if(this == &other) return *this;

	Free();
	Move(std::move(other));

	return *this;

}

ShapeCollection::~ShapeCollection() noexcept{
	Free();
}

void ShapeCollection::AddShape(Shape * const shape){

	if(m_Size == m_Capacity) Resize();
	m_Shapes[m_Size++] = shape;

}

Shape *&ShapeCollection::operator [](size_t index){

	if(index >= m_Size) throw std::out_of_range("Out of range in m_Shapes collection");
	return m_Shapes[index];

}

Shape * const ShapeCollection::operator [](size_t index) const{

	if(index >= m_Size) throw std::out_of_range("Out of range in m_Shapes collection");
	return m_Shapes[index];

}

size_t ShapeCollection::Size() const{
	return m_Size;
}

size_t ShapeCollection::Capacity() const{
	return m_Capacity;
}

bool ShapeCollection::Empty() const{
	return !m_Size;
}

void ShapeCollection::Resize(){

	Shape **newCollection = new Shape *[m_Capacity *= 2];

	for(size_t i = 0; i < m_Size; i++)
		newCollection[i] = m_Shapes[i];

	delete[] m_Shapes;
	m_Shapes = newCollection;

}

void ShapeCollection::Copy(ShapeCollection const &other){

	m_Shapes = new Shape *[other.m_Capacity];
	m_Capacity = other.m_Capacity;
	m_Size = other.m_Size;

	for(size_t i = 0; i < m_Size; i++)
		m_Shapes[i] = other.m_Shapes[i] -> Clone();

}

void ShapeCollection::Move(ShapeCollection &&other) noexcept{

	m_Shapes = std::exchange(other.m_Shapes, nullptr);
	m_Capacity = other.m_Capacity;
	m_Size = other.m_Size;

}

void ShapeCollection::Free() noexcept{

	for(size_t i = 0; i < m_Size; i++)
		delete m_Shapes[i];
	delete[] m_Shapes;
	m_Shapes = nullptr;

}