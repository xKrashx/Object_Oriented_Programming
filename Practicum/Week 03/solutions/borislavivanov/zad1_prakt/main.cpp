#include <iostream>
#include "point.h"
#include "triangle.h"
#include "quadrilateral.h"
int main(){
    point a;
    double offy = 3.50;
    double offx = 1.7;
    triangle ABC;
    quadrilateral ABCD;
    translate(ABCD,offx,offy);
    translate(ABC,offx,offy);
    translate(a,offx,offy);
    std::cout<<ABCD.A.x<<a.y;
    return 0;
}