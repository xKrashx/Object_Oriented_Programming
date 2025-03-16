#include <iostream>
#include <cmath>

struct point {
	int x;
	int y;
};

struct triangle {
	point first;
	point second;
	point third;
	float surface = 0;
};

// Това е излишно!
void clearInput() {
	char c = 0;
	do {
		c = getchar();
	} while (c != '\n' && c != EOF);
}

int validCoor() {
	int temp = -1000;
	do {
		// Правиш живота си твърде труден с управлението на потока.
		// Едни просто cin и cout ти вършат перфектна работа!
		char c = std::cin.peek();
		while (c != '-' && (c < '0' || c > '9')) {
			std::cin.ignore();
			c = std::cin.peek();
		}
		c = getchar();
		if (c == '-') {
			c = std::cin.peek();
			if (c < '0' || c > '9') {
				continue;
			}
		}
		std::cin.unget();
		std::cin >> temp;
		//std::cout << temp << std::endl;
		if (temp < -100 || temp > 100) {
			std::cout << "Invalid input, try again." << std::endl;
			clearInput();
		}
	} while (temp < -100 || temp > 100);
	return temp;
}

void validPoint(point& point) {
	point.x = validCoor();
	//std::cout << "Succsessfully created x coordinate. ";
	point.y = validCoor();
	//std::cout << "Succsessfully created y coordinate. ";
}

void validTri(triangle& tri) {
	validPoint(tri.first);
	//std::cout << "Succsessfully created first point. ";
	validPoint(tri.second);
	//std::cout << "Succsessfully created second point. ";
	validPoint(tri.third);
	//std::cout << "Succsessfully created third point. ";
}

void printArray(const triangle* const arr, const unsigned int size) {
	for (int i = 0; i < size; i++) {
		std::cout /**/ << arr[i].first.x << " " << arr[i].first.y
			<< " " << arr[i].second.x << " " << arr[i].second.y
			<< " " << arr[i].third.x << " " << arr[i].third.y 
			<< " "/**/ << arr[i].surface << '\n';
	}
}

void calculateSurface(triangle& tri) {
	tri.surface = 0.5 * std::abs(tri.first.x * (tri.second.y - tri.third.y)
								+ tri.second.x * (tri.third.y - tri.first.y)
								+ tri.third.x * (tri.first.y - tri.second.y));
}

void swapTri(triangle& first, triangle& second) {
	triangle temp = first;
	first = second;
	second = temp;
}

void BubbleSort(triangle* arr, const unsigned int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j].surface > arr[j + 1].surface) {
				swapTri(arr[j], arr[j + 1]);
			}
		}
	}
}

int main() {
	unsigned int N = 1;
	do {
		std::cin >> N;
		if (N < 1 || N > 1000) {
			std::cout << "Invalid number of triangles. Please enter a number between 1 and 1000." << std::endl;
			clearInput();
		}
	} while (N < 1 || N > 1000);

	std::cout << "Please enter points with coordinates between -100 and 100." << std::endl;
	triangle* arr = new(std::nothrow) triangle[N];
	// Липсва валидация за указателя, ако не е успял да се задели коректно ще имаш проблеми надолу!
	for (int i = 0; i < N; i++) {
		validTri(arr[i]);
		std::cout << "Succsessfully created " << i + 1 << " triangle.\n";
		calculateSurface(arr[i]);
	}
	BubbleSort(arr, N);
	printArray(arr, N);
	delete[] arr;
}