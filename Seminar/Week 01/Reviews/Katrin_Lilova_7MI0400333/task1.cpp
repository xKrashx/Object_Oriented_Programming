// Идеално е разписана задачата
#include "task1.hpp"
#include <cmath>
#include <iostream>

namespace Task1 {
	double getArea(const Triangle& triangle) {
		return 0.5 * std::abs(
			(triangle.vertexes[0].x) * (triangle.vertexes[1].y - triangle.vertexes[2].y) +
			(triangle.vertexes[1].x) * (triangle.vertexes[2].y - triangle.vertexes[0].y) +
			(triangle.vertexes[2].x) * (triangle.vertexes[0].y - triangle.vertexes[1].y));
	}

	void printAreas(const Triangle* triangles, unsigned int count) {
		if (triangles == nullptr) return;

		std::cout << "Triangle areas:" << "\n";

		for (unsigned int i = 0; i < count; i++) {
			std::cout << triangles[i].area << " ";
		}

		std::cout << "\n";
	}

	void readVertexes(Triangle* triangles, unsigned int count) {
		if (triangles == nullptr) return;

		std::cout << "Enter vertex coordinates for each triangle:" << "\n";

		for (unsigned int i = 0; i < count; i++) {
			int x, y;

			for (unsigned int j = 0; j < TRIANGLE_VERTEX_COUNT; j++) {
				do {
					std::cin >> x >> y;
				} while (x < COORD_VALUE_MIN || x > COORD_VALUE_MAX || y < COORD_VALUE_MIN || y > COORD_VALUE_MAX);

				triangles[i].vertexes[j].x = x;
				triangles[i].vertexes[j].y = y;
			}

			triangles[i].area = getArea(triangles[i]);
		}
	}

	void sortAreas(Triangle* triangles, unsigned int count) {
		if (triangles == nullptr) return;

		for (unsigned int i = 1; i < count; i++) {
			Triangle t = triangles[i];
			int j = (int)i - 1;

			while (j >= 0 && t.area < triangles[j].area) {
				triangles[j + 1] = triangles[j];

				j--;
			}

			triangles[j + 1] = t;
		}
	}

	int run() {
		unsigned int n;

		std::cout << "Enter triangle count:" << "\n";

		do {
			std::cin >> n;
		} while (n < TRIANGLE_COUNT_MIN || n > TRIANGLE_COUNT_MAX);

		Triangle* triangles = new(std::nothrow) Triangle[n];

		if (triangles == nullptr) {
			std::cout << "Memory allocation failed." << "\n";

			return 1;
		}

		readVertexes(triangles, n);
		sortAreas(triangles, n);

		printAreas(triangles, n);

		delete[] triangles;
		return 0;
	}
}