#pragma once

// Защо просто не направи още една структура Point, която да пази отделните координати?
struct Triangle {
	double Ax = 0;
	double Ay = 0;
	double Bx = 0;
	double By = 0;
	double Cx = 0;
	double Cy = 0;
	double area = 0;
};

void triangleArea(Triangle& triangle);

double twoDotsDistance(double Ax, double Ay, double Bx, double By);

void triangleBuilder(Triangle& triangle);