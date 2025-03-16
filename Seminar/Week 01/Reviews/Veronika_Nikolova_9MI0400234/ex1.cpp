#include <iostream>
#include <cmath>
 
// Не го използвай, лоша практика е и може да ти се взимат точки на контролни за това.
using namespace std;
 
struct Triangle {
 
    double x1, y1, x2, y2, x3, y3;
    double area;
};
bool isValid(int n) {
    return n >= 1 || n <= 1000;
}
 
bool isValidCoordinates(double x, double y) {
    return x >= -100 && y <= 100;
}
 
 
double calArea(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double b = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    double c = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double p = (a + b + c)/2;
 
    return sqrt(p * (p - a)* (p - b) * (p - c));
}
 
void sort(Triangle triangles[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (triangles[j].area > triangles[j + 1].area) {
                swap(triangles[j], triangles[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // Ако няма размяна, сортирането приключва
    }
}
 
void swap(Triangle &t1, Triangle &t2) {
    Triangle temp = t1;
    t1 = t2;
    t2 = temp;
}
 
void print (Triangle triangle[], int n) {
    for (int i = 0; i < n; i++)
    {
        std::cout << triangle[i].area << endl;
    }
 
}
 
int main() {

    int n;
    std::cin >> n;
    // И какво правим с резултата от isValid?
    // Можеш просто една проверка и ако не е валидно да правиш return.
    isValid(n);
    // Статичен масив с run time променлива е забранено.
    // Ако ще въвеждаш размер -> задължително динамична памет.
    Triangle triangles[n];
 
    for (int i = 0; i < n; i++)
    {
        std::cin >> triangles[i].x1 >> triangles[i].y1
        >> triangles[i].x2 >> triangles[i].y2
        >> triangles[i].x3 >> triangles[i].y3;
        // Отново, какво правим с резултатите от isValidCoordinates?
        isValidCoordinates(triangles[i].x1, triangles[i].y1);
        isValidCoordinates(triangles[i].x2, triangles[i].y2);
        isValidCoordinates(triangles[i].x3, triangles[i].y3);
        triangles[i].area = calArea(triangles[i].x1, triangles[i].y1, triangles[i].x2, triangles[i].y2, triangles[i].x3, triangles[i].y3);
    }
    sort(triangles, n);
    print(triangles, n);
    return 0;
 
 
}