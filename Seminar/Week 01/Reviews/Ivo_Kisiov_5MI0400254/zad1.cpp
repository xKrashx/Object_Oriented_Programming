// General tip:
// Гледай да пишеш по-описателни имена на променливи, където има логика разбира се.
// triangle *t е малко досадно за разбиране в по-голям код.
// Ако става въпрос за размер или пък някакво математическо понятие като страните на триъгълника е ок.
#include<iostream>
#include<cmath>

struct triangle
{
    int x1, x2, x3, y1, y2, y3;
    // Страните не са ти толкова необходими.
    // Единият вариант е да ги смяташ за логаритмично време.
    // Другият е просто да ползваш константната формула за лице на триъгълник от детерминанта.
    double sideA, sideB, sideC;
    double area;
};

// Такъв тип функции по-скоро искаме да бъдат void и да приемат референция към обекта.
triangle readCornersCoordinatesOfTriangle()
{
    triangle t;
    std::cin >> t.x1 >> t.y1 >> t.x2 >> t.y2 >> t.x3 >> t.y3;
    return t;
}

double lengthOfSide(int x1, int y1, int x2, int y2)
{
    return  sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// Защо тук не подаваме направо триъгълника и да викнем 3 пъти lengthOfSide
double AreaOfTriangle(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    return sqrt(s* (s - a) * (s - b) * (s - c));
}

// Лично аз бих го разписал с референции, но и така работи.
void swap(triangle* a, triangle* b)
{
    triangle temp = *a;
    *a = *b;
    *b = temp;
}

// Да превръщаме размера от unsigned int към int може да доведе до проблеми.
// Желателно е да е еднакъв тип навсякъде.
void sort(triangle* t, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if(t[i].area > t[i+1].area)
        {
            swap(&t[i], &t[i + 1]);
        }
    }
}

int main()
{
    unsigned int n;
    std::cin >> n;
    if(n > 1000)
    {
        std::cout << "Invalid data";
        return -1;
    }
    triangle* t = new(std::nothrow) triangle[n];
    if(!t)
    {
        std::cout << "Memory Error!" << std::endl;
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        t[i] = readCornersCoordinatesOfTriangle();
        if(-100 > t[i].x1, t[i].x1 >100 || -100 > t[i].x2, t[i].x2 >100 || -100 > t[i].x3, t[i].x3 >100
         || -100 > t[i].y1, t[i].y1 >100 || -100 > t[i].y2, t[i].y2 >100 || -100 > t[i].y3, t[i].y3 >100)
        {
            // Трябва да освободим и паметта, ако искаме да приключим програмата тук.
            std::cout << "Invalid data";
            return -1;
        }
        t[i].sideA = lengthOfSide(t[i].x1, t[i].y1, t[i].x2, t[i].y2);
        t[i].sideB = lengthOfSide(t[i].x2, t[i].y2, t[i].x3, t[i].y3);
        t[i].sideC = lengthOfSide(t[i].x3, t[i].y3, t[i].x1, t[i].y1);
        t[i].area = AreaOfTriangle(t[i].sideA, t[i].sideB, t[i].sideC);
    }

    // Този триъгълник от къде се spawn-а?
    triangle temp;

    sort(t, n);

    for (int i = 0; i < n; i++)
    {
        std::cout << t[i].area << " ";
    }
    std::cout << std::endl;

    delete[] t;
}