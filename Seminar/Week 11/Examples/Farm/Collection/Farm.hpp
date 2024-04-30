#ifndef __FARM_HPP_
#define __FARM_HPP_

#include "../Animals/Animal.hpp"
#include <cstddef>

class Farm{

public:
	Farm();
	Farm(Farm const &other);
	Farm(Farm &&other) noexcept;
	Farm &operator=(Farm const &other);
	Farm &operator=(Farm &&other) noexcept;
	~Farm() noexcept;

	void AddAnimal(Animal const *animal);

	void AllTalk() const;

private:
	void Resize();
	void Copy(Farm const &other);
	void Move(Farm &&other) noexcept;
	void Free() noexcept;

private:
	size_t m_Size, m_Capacity;
	Animal **m_Animals;

};

#endif