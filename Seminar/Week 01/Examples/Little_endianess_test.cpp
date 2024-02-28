#include <iostream>

bool isLittleEndian(){

	union{ // Anonymous union
		uint32_t n = 1;			// 1 * 4bytes
		unsigned char bytes[4]; // 4 * 1bytes
	}myTest; // Variable

	// If little endian n -> 0x01000000
	// If big endian n -> 0x00000001

	// Check the first byte
	return myTest.bytes[0];

}

int main(){

   std::cout << isLittleEndian() << '\n';

}