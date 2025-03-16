// Преговори референциите!
#include<iostream>

struct complexNum
{
    int a, b, c, d;
    int z1, z2;
};

void printResult(complexNum* c)
{
    if(c->z2 == 0)
    {
        std::cout << c->z1 << std::endl;
    }
    else if(c->z1 == 0)
    {
        std::cout << c->z2 << "i" << std::endl;
    }
    else
    {
        if(c->z2 > 0)
        {
            std::cout << c->z1 << "+" << c->z2 << "i" << std::endl;
        }
        else
        {
            std::cout << c->z1 << c->z2 << "i" << std::endl;
        }
    }
}


// От функции като add, subtract, multiply и т.н.
// очаквам само да направят операцията и да ми върнат резултат.
// Не очаквам и да го принтират също.
// Тогава трябваше да се казват AddAndPrint.
void addition(complexNum* c)
{
    c->z1 = (c->a + c->c);
    c->z2 = (c->b + c->d);
    printResult(c);
}

void subtraction(complexNum* c)
{
    c->z1 = (c->a - c->c);
    c->z2 = (c->b - c->d);

    printResult(c);
}

void multiplication(complexNum* c)
{
    c->z1 = (c->a * c->c - c->b * c->d);
    c->z2 = (c->a * c->d + c->b * c->c);

    printResult(c);
}

int main()
{
    complexNum c;
    std::cin >> c.a >> c.b >> c.c >> c.d;
    if(c.a < -1000 || c.a > 1000 || c.b < -1000 || c.b > 1000 || c.c < -1000 || c.c > 1000 || c.d < -1000 || c.d > 1000)
    {
        std::cout << "Invalid data";
        return -1;
    }

    addition(&c);
    subtraction(&c);
    multiplication(&c);
}