#include <iostream>

struct Point {
	int x;
	int y;
};

float readTriangleArea();
float mod(float x);
void sortAreas(float * areas, size_t size);
void printAreas(float * areas, size_t size);

int main() {
	size_t size = 0;
	std::cin >> size;
	// По условие ти се изисква да създаваш и сортираш триъгълници, а не лица.
	// Имай го предвид, защото на контролни и изпит е твърде възможно да ти се заядат за някакъв такъв детайл.
	float * areas = new(std::nothrow) float[size];
	if (!areas) {
		std::cerr << "Out of memory" << std::endl;
		return 0;
	}

	for (size_t i = 0; i < size; ++i) {
		areas[i] = readTriangleArea();
	}

	sortAreas(areas, size);
	printAreas(areas, size);

	delete[] areas;
	return 0;
}

float readTriangleArea() {
	Point a, b, c;
	std::cin
		>> a.x >> a.y
		>> b.x >> b.y
		>> c.x >> c.y;

	// Можеш да използваш std::abs.
	return mod((a.x*b.y + a.y*c.x + b.x*c.y - a.y*b.x - a.x*c.y - b.y*c.x) / 2.0f);
}

float mod(float x) {
	return x < 0 ? -x : x;
}

void sortAreas(float * areas, size_t size) {
	float m = 0.0;
	for (size_t i = 0; i < size - 1; ++i) {
		for (size_t j = i + 1; j < size; ++j) {
			if (areas[i] > areas[j]) {
				m = areas[j];
				areas[j] = areas[i];
				areas[i] = m;
			}
		}
	}
}

void printAreas(float * areas, size_t size) {
	// Това просто изглежда грешно, макар и да е вярно XD.
	// Аз лично бих го вкарал в цикъла и да кажа следното:
	// if (i) std::cout << ' ';
	// std::cout << areas[i];
	if (size) {
		std::cout << areas[0];
	}
	for (size_t i = 1; i < size; ++i) {
		std::cout << " " << areas[i];
	}
	std::cout << std::endl;
}