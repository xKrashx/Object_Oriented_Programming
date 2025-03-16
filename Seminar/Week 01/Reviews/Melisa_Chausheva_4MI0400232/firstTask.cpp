#include <iostream>
#include <cmath>
#include <new>

struct Point 
{
    int x, y;
};

struct Triangle
{
    Point p1, p2, p3;

    // За методи все още не сме говорили, трябва да се придържаме към нещата, които сме говорили.
    double calculateArea()
    {
        double a = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
        double b = sqrt(pow(p3.x - p2.x, 2) + pow(p3.y - p2.y, 2));
        double c = sqrt(pow(p3.x - p1.x, 2) + pow(p3.y - p1.y, 2));
        double p = (a + b + c) / 2;

        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

// Функцията не е грешно разписана, аз просто бих подал параметрите като референции(double&).
void swap(double* a, double* b) 
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(double arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++) 
        {
            if (arr[j] < arr[min]) 
            {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}

int main()
{
    // Макар и да има валидация за размера е хубаво да свикнем
    // да правим размера unsigned число, за да нямаме проблеми.
    int n;
    std::cin >> n;

    if (n < 1 || n > 1000) 
    {
        std::cout << "Invalid input!";
        return 1;
    }

    // В условието се изискваше да се сортират триъгълници, а не просто лица.
    // Това е същото като да ти дам за задача да сортираш шишета на рафт спрямо височината им и ти се върнеш с един лист,
    // на който си написал височините в сортиран ред. Реално заобикаляш проблема.
    // За такива уточнения на контролно и изпит е напълно възможно да ти се анулира задачата, защото не е по условието.
    double* areas = new(std::nothrow) double[n];
    if (areas == nullptr)
    {
        std::cout << "Memory error!";
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        Triangle triangle;
        std::cin >> triangle.p1.x >> triangle.p1.y >> triangle.p2.x >> triangle.p2.y >> triangle.p3.x >> triangle.p3.y;
        areas[i] = triangle.calculateArea();
    }

    selectionSort(areas, n);

    for (int i = 0; i < n; i++)
    {
        std::cout << areas[i];
        if (i < n - 1)
        {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    delete[] areas;

    return 0;
}