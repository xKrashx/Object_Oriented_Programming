#pragma once

namespace Task1 {
	const unsigned int TRIANGLE_COUNT_MAX = 1000;
	const unsigned int TRIANGLE_COUNT_MIN = 1;

	const unsigned int TRIANGLE_VERTEX_COUNT = 3;

	const int COORD_VALUE_MAX = 100;
	const int COORD_VALUE_MIN = -100;

	struct Vertex {
		int x;
		int y;
	};

	struct Triangle {
		double area;
		Vertex vertexes[TRIANGLE_VERTEX_COUNT];
	};

	int run();
	void readVertexes(Triangle* triangles, unsigned int count);

	double getArea(const Triangle& triangle);
	void printAreas(const Triangle* triangles, unsigned int count);
	void sortAreas(Triangle* triangles, unsigned int count);
}