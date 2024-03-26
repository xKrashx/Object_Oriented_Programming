#include "quadrilateral.h"

void read(Quadrilateral& quadrilateral)
{
    read(quadrilateral.a);
    read(quadrilateral.b);
    read(quadrilateral.c);
    read(quadrilateral.d);
}

void print(const Quadrilateral& quadrilateral)
{
    print(quadrilateral.a);
    print(quadrilateral.b);
    print(quadrilateral.c);
    print(quadrilateral.d);
}

void translate(Quadrilateral& quadrilateral, float offX, float offY)
{
    translate(quadrilateral.a, offX, offY);
    translate(quadrilateral.b, offX, offY);
    translate(quadrilateral.c, offX, offY);
    translate(quadrilateral.d, offX, offY);
}
