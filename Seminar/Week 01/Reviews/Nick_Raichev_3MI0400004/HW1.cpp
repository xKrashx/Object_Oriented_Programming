#include <iostream>

// Бих си добавил и една малка структурка Point, за да мога по-лесно да подавам точките като аргументи.
struct Triangle {
    int x1, y1, x2, y2, x3, y3;
    double area;
};

// Calculate the area of a triangle
double calculateTriangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
    return std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
}

// Read triangle data from input
void readTriangles(Triangle* triangles, int n) {
    for (int i = 0; i < n; i++) {
        std::cin >> triangles[i].x1 >> triangles[i].y1
            >> triangles[i].x2 >> triangles[i].y2
            >> triangles[i].x3 >> triangles[i].y3;
        triangles[i].area = calculateTriangleArea(
            triangles[i].x1, triangles[i].y1,
            triangles[i].x2, triangles[i].y2,
            triangles[i].x3, triangles[i].y3
        );
    }
}

// Print triangle areas
void printTriangleAreas(Triangle* triangles, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << triangles[i].area;
        if (i < n - 1) std::cout << " ";
    }
    std::cout << std::endl;
}

// Sort triangles by their area using Selection Sort
void sortTriangles(Triangle* triangles, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (triangles[j].area < triangles[minIndex].area) {
                minIndex = j;
            }
        }
        Triangle temp = triangles[i];
        triangles[i] = triangles[minIndex];
        triangles[minIndex] = temp;
    }
}

int main() {
    int N;
    std::cin >> N;
    // Нямаш валидация за N!
    // Какво става ако въведа отрицателна стойност?!?

    // Липсва std::nothrow като аргумент на оператор new, което може да доведе до crash.
    Triangle* triangles = new Triangle[N];

    // Нямаш валидация дали указателят е правилно заделен.

    readTriangles(triangles, N);

    sortTriangles(triangles, N);

    printTriangleAreas(triangles, N);

    delete[] triangles;

    return 0;
}
