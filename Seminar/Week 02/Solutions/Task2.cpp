#include <iostream>
#include <cstddef>
#include <cstring>
#include <fstream>
#include <new>

char const * const name = "MyData.dat";

size_t getFileSize(std::ifstream &f){

	size_t currentPos = f.tellg();

	f.seekg(0, std::ios::end);
	size_t size = f.tellg();

	f.seekg(currentPos);
	return size;

}

void resize(char *data, size_t &size, size_t const newSize){

	char *newDataArr = new char[newSize];
	
	size_t minSize = std::min(size, newSize);
	for(size_t i = 0; i < minSize; i++)
		newDataArr[i] = data[i];

	delete[] data;
	data = newDataArr;
	size = newSize;

}

char convertSymbolToNumber(char const symbol){

	if(symbol >= '0' && symbol <= '9') return symbol - '0';
	else if(symbol >= 'A' && symbol <= 'Z') return symbol - 'A' + 10;
	return '\0';

}

void addByte(char *&data, size_t &size, char const *byteStr){

	if(strlen(byteStr) != 2) return;

	char currentByte = 16 * convertSymbolToNumber(byteStr[0]) + convertSymbolToNumber(byteStr[1]);

	resize(data, size, size + 1);
	data[size - 1] = currentByte;

}

void removeLastByte(char *&data, size_t &size){

	if(size == 0) return;
	resize(data, size, size - 1);

}

void changeByte(char * const data, size_t const size, size_t const index, char const * const byteStr){
	
	if(index >= size || strlen(byteStr) != 2) return;

	char currentByte = convertSymbolToNumber(byteStr[1]) + 16 * convertSymbolToNumber(byteStr[0]);
	data[index] = currentByte;

}

void convertToHex(char const byte, char * const byteHex){

	char symbols[] = { '0','1', '2', '3', '4', '5', '6','7',
					  '8','9', 'A', 'B', 'C', 'D', 'E', 'F' };

	byteHex[2] = '\0';
	byteHex[1] = symbols[byte % 16];
	byteHex[0] = symbols[(byte / 16) % 16];

}

bool isLetter(char const ch){
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void print(char const * const data, size_t const size){

	char byteHex[3];

	for(size_t i = 0; i < size; ++i){

		convertToHex(data[i], byteHex);
		std::cout << byteHex << ' ';

	}

	std::cout << '\n';
	
	for(size_t i = 0; i < size; ++i){

		if(isLetter(data[i])) std::cout << data[i];
		else std::cout << '.';
		std::cout << ' ';

	}

	std::cout << '\n';

}

void save(char const * const data, size_t const size){

	std::ofstream file(name, std::ios::binary);

	if(!file.is_open()){
		
		std::cout << "Couldn't save\n";
		return;
	
	}

	file.write((const char *)data, size);

	file.close();

}

void saveAs(char const * const fileName, char const * const data, size_t const size){

	std::ofstream file(fileName, std::ios::binary);

	if(!file.is_open()){
		
		std::cout << "Couldn't save\n";
		return;
	
	}

	file.write((const char *)data, size);

	file.close();

}

int main(){

	std::ifstream file(name, std::ios::binary);

	if(!file.is_open()){

		std::cout << "Error\n";
		return -1;

	}

	size_t size = getFileSize(file);
	char *data = new(std::nothrow) char[size];

	if(!data){

		std::cout << "Memory error\n";
		return -1;

	}

	file.read((char *)data, size);

	print(data, size);
	addByte(data, size, "FF");
	print(data, size);

	removeLastByte(data, size);
	print(data, size);

	changeByte(data, size, 3, "63");
	print(data, size);

	saveAs("newData.dat", data, size);

	delete[] data;
	return 0;

}