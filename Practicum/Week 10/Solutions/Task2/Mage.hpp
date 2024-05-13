#ifndef __MAGE_HPP
#define __MAGE_HPP

#include "Player.hpp"

class Mage : public Player
{
	public:
		Mage(const char* name, const char* power);
		Mage(const Mage& other);

		~Mage();

		Mage& operator=(const Mage& other);

		const char* GetPower() const;
		void SetPower(const char* power);

		void Print(std::ostream& os = std::cout) const;

	private:
		static const unsigned short MAX_LEN;
		char* power;
};

#endif