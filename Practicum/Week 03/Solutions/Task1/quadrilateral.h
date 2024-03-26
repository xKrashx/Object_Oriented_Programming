#ifndef __QUADRILATERAL_H
#define __QUADRILATERAL_H

#include "point.h"

struct Quadrilateral
{
    Point a, b, c, d;
};

void read(Quadrilateral& quadrilateral);
void print(const Quadrilateral& quadrilateral);

void translate(Quadrilateral& quadrilateral, float offX, float offY);

#endif
