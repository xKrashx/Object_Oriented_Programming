#ifndef __ANIMAL_HPP_
#define __ANIMAL_HPP_

class Animal{

public:
	virtual ~Animal() noexcept {} //!!!

	virtual void Talk() const = 0;
	virtual Animal *Clone() const = 0; //!!!

};

#endif