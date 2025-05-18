#include "Collection/Farm.hpp"
#include "Factory/Factory.hpp"
#include <stdexcept>
#include <iostream>

int main(){

	try{

		Farm f;
		f.AddAnimal(Factory(AnimalType::Cat));
		f.AddAnimal(Factory(AnimalType::Dog));

		f.AllTalk();

	}
	catch(std::bad_alloc){
		std::cerr << "Bad alloc\n";
	}

	return 0;

}