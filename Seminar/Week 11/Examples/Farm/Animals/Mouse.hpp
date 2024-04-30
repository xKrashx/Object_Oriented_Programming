#ifndef __MOUSE_HPP_
#define __MOUSE_HPP_

#include "Animal.hpp"

class Mouse : public Animal{

public:
	void Talk() const override;
	Animal *Clone() const override;

};

#endif