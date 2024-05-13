#include <iostream>
#include <stdexcept>

#include "Player.hpp"
#include "Mage.hpp"

int main() 
{
	try 
	{
		Player player("Roni");
		player.SetPosition(Point(13, 15));
		player.SetPoints(50);
		player.Print();

		std::cout << std::endl;

		Mage mage("Scarlet Witch", "reality manipulation");
		mage.SetPosition(Point(25, 0));
		mage.SetPoints(500);
		mage.Print();
	} 
	catch(std::bad_alloc msg) 
	{
		std::cout << msg.what() << std::endl;
	} 
	catch(std::invalid_argument msg) 
	{
		std::cout << msg.what() << std::endl;
	}

	return 0;
}
