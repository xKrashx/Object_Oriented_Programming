#include<iostream>
#include<cmath>

struct quadEquation
{
    double a, b, c;
    double d;
    double x1, x2;
};

// Тук можеш да го подадеш като референция, за да си спестиш дереференцирането.
void findDiscriminat(quadEquation* q)
{
    (*q).d = pow((*q).b, 2) - 4 * (*q).a * (*q).c;
}

// Същата забележка и тук.
void findSolutions(quadEquation* q)
{
    findDiscriminat(q);
    if((*q).d < 0)
    {
        std::cout << "The equation does not have real solutions!";
        return;
    }
    else if((*q).d == 0)
    {
        (*q).x1 = (*q).x2 = -(*q).b / (2 * (*q).a);
        std::cout << "x1 = x2 = " << (*q).x1;
        return;
    }
    else
    {
        (*q).x1 = (-(*q).b + sqrt((*q).d)) / (2 * (*q).a);
        (*q).x2 = (-(*q).b - sqrt((*q).d)) / (2 * (*q).a);
        if((*q).x1 > (*q).x2)
        {
            double temp = (*q).x1;
            (*q).x1 = (*q).x2;
            (*q).x2 = temp;
        }
        std::cout << "x1 = " << (*q).x1 << ", " << "x2 = " << (*q).x2;
        return;
    }
}

int main()
{
    quadEquation q;
    std::cin >> q.a >> q.b >> q.c;
    if(q.a < -100 || q.a > 100 || q.b < -100 || q.b > 100 || q.c < -100 || q.c > 100)
    {
        std::cout << "Invalid data";
        return -1;
    }
    findSolutions(&q);
}