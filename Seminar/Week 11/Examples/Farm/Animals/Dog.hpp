#ifndef __DOG_HPP_
#define __DOG_HPP_

#include "Animal.hpp"

class Dog : public Animal{

public:
	void Talk() const override;
	Animal *Clone() const override;

};

#endif