// Добре разписана задача
#include <iostream>
#include "triangle.hpp"

int validateInput() {
	int n;
	std::cout << "Enter the number of triangles." << std::endl;
	std::cout << "N = ";
	std::cin >> n;

	while (n < 1 || n > 1000) {
		std::cout << "Input must be in range 1 <= N <= 1000" << std::endl;
		std::cout << "N = ";
		std::cin >> n;
	}

	return n;
}

int main() {
	int n = validateInput();
	Triangle* triangles = new (std::nothrow) Triangle[n];

	if (!triangles) {
		std::cout << "Memory allocation error!" << std::endl;
		return 1;
	}

	for (int i = 0; i < n; i++) {
		std::cout << "Triangle " << i + 1 << std::endl;
		triangleBuilder(triangles[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		bool flag = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (triangles[j].area > triangles[j + 1].area) {
				Triangle temp = triangles[j];
				triangles[j] = triangles[j + 1];
				triangles[j + 1] = temp;

				flag = true;
			}
		}

		if (!flag) {
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		std::cout << triangles[i].area << std::endl;
	}

	delete[] triangles;
	return 0;
}