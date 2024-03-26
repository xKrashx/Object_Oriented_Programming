#include "triangle.h"

void read(Triangle& triangle)
{
    read(triangle.a);
    read(triangle.b);
    read(triangle.c);
}

void print(const Triangle& triangle)
{
    print(triangle.a);
    print(triangle.b);
    print(triangle.c);
}

void translate(Triangle& triangle, float offX, float offY)
{
    translate(triangle.a, offX, offY);
    translate(triangle.b, offX, offY);
    translate(triangle.c, offX, offY);
}
