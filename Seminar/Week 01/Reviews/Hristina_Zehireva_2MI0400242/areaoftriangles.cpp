#include <iostream>
#include <cmath>

struct Point{
    int x;
    int y;
};

struct Triangle{
    Point A;
    Point B;
    Point C;
    double area;
};

double distance(const Point &A, const Point &B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));

}

void calculateArea(Triangle &trian)
{
    double a = distance(trian.A, trian.B);
    double b = distance(trian.A, trian.C);
    double c = distance(trian.B, trian.C);

    double halfperimeter = (a + b + c) / 2;
    trian.area = sqrt(halfperimeter * (halfperimeter - a) * 
                    (halfperimeter - b) * (halfperimeter - c));


}

void sortArea(Triangle *trian, const int size)  // bubble sort
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (trian[i].area > trian[j].area)
            {
                std::swap(trian[i],trian[j]);
            }
            
        }
        
    }
    
}


int main()
{
    int n;
    do
    {
        std::cin >> n;
    } while (n <= 1 && n >= 1000);

    // Липсва std::nothrow като аргумент на оператора new, което може да
    // доведе до crash на програмата и се води като голяма грешка!
    Triangle *trian = new Triangle[n];

    // Липсва валидация за указателя, което може да доведе до проблеми при по-нататъчната му употреба!


    for (int i = 0; i < n; i++)
    {
        std::cin >> trian[i].A.x >> trian[i].A.y
                 >> trian[i].B.x >> trian[i].B.y
                 >> trian[i].C.x >> trian[i].C.y;
        
        calculateArea(trian[i]);
    }
    
    sortArea(trian,n);

    for (int i = 0; i < n; i++)
    {
        std::cout << trian[i].area << ' ';
    }
    
    delete[] trian;


    return 0;
}