#include"2D_system.h"
Coordinate_Sys::Coordinate_Sys(Nvector v1, Nvector v2) {
	Nvector myvec_x(2);
	Nvector myvec_y(2);
	myvec_x.Setcoordinate(0, v1[0]);
	myvec_x.Setcoordinate(1, v1[1]);

	myvec_y.Setcoordinate(0, v2[0]);
	myvec_y.Setcoordinate(1, v2[1]);

	this->vec_x = myvec_x;
	this->vec_y = myvec_y;
}
Coordinate_Sys::Coordinate_Sys() {
	Nvector myvec_x(2);
	Nvector myvec_y(2);
	this->vec_x = myvec_x;
	this->vec_y = myvec_y;
}
double Coordinate_Sys::determinant()const {
	return vec_x[0] * vec_y[1] - vec_x[1] * vec_y[0];
}
Nvector Coordinate_Sys::getVectorByCoordinates(double x_axis, double y_axis)const {
	Nvector result(2);
	double val1 = x_axis * vec_x[0]+y_axis*vec_y[0];//matrix multiplication
	double val2 = x_axis * vec_x[1] + y_axis * vec_y[1];
	result.Setcoordinate(0, val1);
	result.Setcoordinate(1, val2);
	return result;
}
Nvector Coordinate_Sys::getCoordinatesByVector(double x_axis, double y_axis)const {
	Nvector result(2);
	double val1 = x_axis * vec_y[1] - y_axis * vec_y[0];
	double val2 = -x_axis * vec_x[1] + y_axis * vec_x[0];
	result.Setcoordinate(0, val1*(1/this->determinant()));
	result.Setcoordinate(1, val2*(1/this->determinant()));
	return result;
}
