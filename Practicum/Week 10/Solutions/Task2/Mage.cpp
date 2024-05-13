#include "Mage.hpp"

#include <cstring>

const unsigned short Mage::MAX_LEN = 25;

Mage::Mage(const char* name, const char* power) : Player(name), power(nullptr) 
{
	this->SetPower(power);
}

Mage::Mage(const Mage& other) : Player(other), power(nullptr)
{
	this->SetPower(other.power);
}

Mage::~Mage()
{
	delete[] this->power;
	this->power = nullptr;
}

Mage& Mage::operator=(const Mage& other)
{
	if(this != &other)
	{
		Player::operator=(other);
		this->SetPower(other.power);
	}
	return *this;
}

const char* Mage::GetPower() const 
{
	return this->power;
}

void Mage::SetPower(const char* power) 
{
	const unsigned short powerLen = strlen(power);

	if(!power || powerLen >= MAX_LEN)
	{
		throw std::invalid_argument("Invalid power name!");
	}

	delete[] this->power;
	this->power = new char[powerLen + 1];
	strcpy(this->power, power);
}

void Mage::Print(std::ostream& os) const 
{
    if(os.fail() || os.bad()) return;

	Player::Print(os);
    os << "power: "     << (this->power ? this->power : "") << std::endl;
}
