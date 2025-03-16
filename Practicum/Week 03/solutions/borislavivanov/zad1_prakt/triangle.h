#pragma once
#include "point.h"

struct triangle
{
    point A;
    point B;
    point C;
};
void translate (triangle& ABC,double offx,double offY);
