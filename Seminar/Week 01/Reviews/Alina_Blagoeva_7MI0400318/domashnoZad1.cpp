#include <iostream>
#include <new>
#include <cmath>

struct Dot {
    int x;
    int y;
};

// Според мен тази структура е изцяло излишна. Аз лично бих си пазил само 3те точки в триъгълника.
// Ако държиш да пазиш страната по някакъв начин, начало и край заедно с дължина е в повече(хабиш памет),
// тъй като дължината можеш да изчислиш с двете точки в логаритмично време(заради sqrt) с питагорова формула.
struct Side {
    Dot start;
    Dot end;
    double size;
};

// В тази структура бих използвал само точките и потенциално лицето, ако не искам да го смятам всеки път(въпреки, че мога за константно време).
struct Triangle {
    double area;
    Side sideA;
    Side sideB;
    Side sideC;
};

// Тази функция не прави нищо! Въвеждат се стойности на локални променливи, които се освобождават, в края на scope-а на функцията.
// Обект, който е по-голям от 8byte-а(Triangle) трябва да се подава по референция!!!
void getDot(Triangle triangle) {
    int x, y;
    std::cout << "-100 <= xi, yi <= 100\nx = ";
    std::cin >> x;
    std::cout << "y = ";
    std::cin >> y;
}

// Функцията не прави нищо!
// Обект, който е по-голям от 8byte-а(Triangle) трябва да се подава по референция!!!
void getTriangleDots(Triangle triangle) {
    char dots[] = { 'a', 'b', 'c'};

    for (char ch: dots) {
        std::cout << "Dot " << ch << std::endl;
        getDot(triangle);
    }
}

double getSideLen(Dot first, Dot second) {
    int formula = (second.x - first.x)*(second.x - first.x) + (second.y - first.y) * (second.y - first.y);
    
    return sqrt(formula);
}

void getSides(Triangle &triangle) {
    triangle.sideA.size = getSideLen(triangle.sideA.start, triangle.sideA.end);
    triangle.sideA.size = getSideLen(triangle.sideB.start, triangle.sideB.end);
    triangle.sideA.size = getSideLen(triangle.sideC.start, triangle.sideC.end);

}

double getTriangleArea(Triangle &triangle) {
    double a = triangle.sideA.size, b = triangle.sideB.size, c = triangle.sideC.size;

    double p = (a + b + c) / 3;
    double formulaArea = p*(p - a)*(p - b)*(p - c);
    
    return sqrt(formulaArea);
}

void getTriangle(Triangle &triangle) {
    getTriangleDots(triangle);

    triangle.area = getTriangleArea(triangle); // Всеки път ще е случайна, заради функциите за вход!!!
}

void sort(Triangle arr[]) {
    //selection sort

}

void printTriangleAreas(const Triangle* arr, int size) {
    for (int i = 0; i < size; i++) {
        // Скобите не са нужни за адресиране на конкретния обект, но не пречи да ги има.
        std::cout << (arr[i]).area << std::endl;
    }
}

int main()
{
    // Добра практика е за индексации и пазене на размери на структури да се използват unsigned числа(size_t за предпочитане).
    // = NULL просто крещи ужас за мен! NULL е макро, което първо се използва само в C и второ се използва за указатели.
    // Ако искаш да кажеш, че размерът е 0, просто напиши 0!
    // Имай предвид, че 2 реда по-надолу ще изискваш от конзолата вход, който ще презапише стойността така или иначе.
    int n = NULL;
    std::cout << "1 <= N <= 1000\nN = ";
    std::cin >> n;

    // Тук липсата на валидация на n ти играе много лоша шега.
    // Наясно ли си какво става, ако въведа число по-малко от 1?
    // При 0 ще работи, но изглежда странно и не е функционално.
    // При отрицателни стойности няма да работи като цяло.
    Triangle* arr = new(std::nothrow) Triangle[n];
    if (!arr) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        std::cout << "3 dost for the" << i+1 << "triangle" << std::endl;
        getTriangle(arr[i]);
    }
    
    sort(arr);
    printTriangleAreas(arr, n);

    // Огромна грешка тук е, че не се освобождава паметта. Това се счита за учено по УП и тук се таксува строго, ако липсва.
    // Лично аз започвайки да пиша код обвързан с динамична памет винаги я заделям проверявам и освобождавам първо!
    // Преди да започна да я използвам, за да съм сигурен, че когато съм готов всичко ще работи.

}
