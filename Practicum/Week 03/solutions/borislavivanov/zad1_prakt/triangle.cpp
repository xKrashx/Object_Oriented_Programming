#include "point.h"
#include "triangle.h"

void translate (triangle& ABC,double offx,double offY){
    translate(ABC.A,offx,offY);
    translate(ABC.B,offx,offY);
    translate(ABC.C,offx,offY);
}