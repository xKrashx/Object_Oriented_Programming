#include <iostream>
#include <fstream>

struct Test{

	bool b;
	int x;

};

int main(){

	{   // write

		Test t = { true, 45 };
		std::ofstream file("testObj.bat", std::ios::binary | std::ios::trunc);

		if(!file.is_open()) return -1;

		file.write((const char*)&t, sizeof(t));

		file.close();

	}

	{   // read

		Test t;
		std::ifstream file("testObj.bat", std::ios::binary);
		
		if(!file.is_open()) return -1;

		file.read((char*)&t, sizeof(t));

		std::cout << t.b << " " << t.x << '\n';

		file.close();

	}

	return 0;

}
