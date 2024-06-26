#pragma once
#include "Geometric_vector.h"
class Coordinate_Sys {
public:
	Coordinate_Sys(Nvector v1, Nvector v2);
	Coordinate_Sys();

	Nvector getVectorByCoordinates(double x_axis, double y_axis)const;
	Nvector getCoordinatesByVector(double x_axis, double y_axis)const;
	double determinant()const;
private:
	Nvector vec_x;
	Nvector vec_y;
};
