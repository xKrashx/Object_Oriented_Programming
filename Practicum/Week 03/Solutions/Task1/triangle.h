#ifndef __TRIANGLE_H
#define __TRIANGLE_H

#include "point.h"

struct Triangle
{
    Point a, b, c;
};

void read(Triangle& triangle);
void print(const Triangle& triangle);

void translate(Triangle& triangle, float offX, float offY);

#endif
