#include <iostream>
#include <cmath>

struct Point {
	int x, y;
};

struct Triangle{
	Point p1, p2, p3;

	// Методи все още не са учени.
	// Макар и да е добре написан се въздържаме от употребата им докато не ги вземем,
	// за да избегнем кофти коментари и неудобни въпроси от преподаватели.
	double area() const {
		return std::abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) / 2.0);
	}
};

void sortTriangles(Triangle *triangles,int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (triangles[j].area() > triangles[j + 1].area()) {
				Triangle temp = triangles[j];
				triangles[j] = triangles[j + 1];
				triangles[j + 1] = temp;
			}
		}
	}
}

int main() {
	int n;
	do {
		std::cin >> n;
	} while (n < 1 || n > 1000);
	// Защо да въвеждаме размер, като винаги ще имаме 10 елемента?!?
	// Тук трябва задължително да се използва динамична памет.
	Triangle triangles[10];
	for (int i = 0; i < n; i++) {
		std::cin >> triangles[i].p1.x >> triangles[i].p1.y
				 >> triangles[i].p2.x >> triangles[i].p2.y
				 >> triangles[i].p3.x >> triangles[i].p3.y;
	}

	sortTriangles(triangles, n);

	for (int i = 0; i < n; i++) {
		std::cout << triangles[i].area() << " ";
	}

	return 0;
}