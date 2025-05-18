#include "Farm.hpp"
#include <utility>

Farm::Farm(): m_Capacity(4), m_Size(0), m_Animals(new Animal *[m_Capacity]){}

Farm::Farm(Farm const &other){
	Copy(other);
}

Farm::Farm(Farm &&other) noexcept{
	Move(std::move(other));
}

Farm &Farm::operator =(Farm const &other){

	if(this == &other) return *this;

	*this = Farm(other);

	return *this;

}

Farm &Farm::operator =(Farm &&other) noexcept{

	if(this == &other) return *this;

	Free();
	Move(std::move(other));

	return *this;

}

Farm::~Farm(){
	Free();
}

void Farm::AddAnimal(Animal const *new_animal){

	if(m_Size == m_Capacity) Resize();
	m_Animals[m_Size++] = new_animal -> Clone();

}

void Farm::AllTalk() const{

	for(size_t i = 0; i < m_Size; i++)
		m_Animals[i] -> Talk();

}

void Farm::Resize(){

	Animal **newCollection = new Animal *[m_Capacity *= 2];
	for(size_t i = 0; i < m_Size; i++)
		newCollection[i] = m_Animals[i];

	delete[] m_Animals;
	m_Animals = newCollection;

}

void Farm::Copy(Farm const &other){

	m_Animals = new Animal *[other.m_Capacity];
	m_Capacity = other.m_Capacity;
	m_Size = other.m_Size;

	for(size_t i = 0; i < m_Size; i++)
		m_Animals[i] = other.m_Animals[i] -> Clone();

}

void Farm::Move(Farm &&other) noexcept{

	m_Animals = std::exchange(other.m_Animals, nullptr);
	m_Capacity = other.m_Capacity;
	m_Size = other.m_Size;

}

void Farm::Free() noexcept{

	for(size_t i = 0; i < m_Size; i++)
		delete m_Animals[i];
	delete[] m_Animals;
	m_Animals = nullptr;

}