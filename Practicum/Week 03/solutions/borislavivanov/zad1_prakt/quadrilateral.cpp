#include "point.h"
#include "quadrilateral.h"

void translate(quadrilateral& ABCD,double offX,double offY){
        translate(ABCD.A,offX,offY);
        translate(ABCD.B,offX,offY);
        translate(ABCD.C,offX,offY);
        translate(ABCD.D,offX,offY);
}