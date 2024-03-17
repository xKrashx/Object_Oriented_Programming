#pragma once
#include "point.h"

struct quadrilateral
{
    point A;
    point B;
    point C;
    point D;
};

void translate(quadrilateral& ABCD,double offX,double offY);
