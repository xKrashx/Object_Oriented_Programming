#ifndef __CAT_HPP_
#define __CAT_HPP_

#include "Animal.hpp"

class Cat : public Animal{

public:
	void Talk() const override;
	Animal *Clone() const override;

};

#endif