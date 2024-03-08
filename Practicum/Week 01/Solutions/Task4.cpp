#include <iostream>
#include <cstddef>

union IpAddress{

	uint32_t address;
	uint8_t octets[4];

};

int main(){

	IpAddress myAddress;
    // 16777343 -> 0x0100007F
    // If little endian -> [ 0x7F, 0x00, 0x00, 0x01 ] -> [ 127, 0, 0, 1 ]
	myAddress.address = 0x0100007F;

	std::cout << (uint32_t)myAddress.octets[0] << '.'
	          << (uint32_t)myAddress.octets[1] << '.'
	          << (uint32_t)myAddress.octets[2] << '.'
	          << (uint32_t)myAddress.octets[3] << '\n';

    return 0;

}