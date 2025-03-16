#pragma once

namespace Task2 {
	const double COEF_VALUE_MAX = 100;
	const double COEF_VALUE_MIN = -100;

	// Единствена забележка имам тук, че бих пазил по-малко данни в самата структура.
	// Например дискриминантата е нещо, което се изчислява за линейно време и ти трябва само
	// във функцията за намиране на корените. Така че може само там да я смятаме и да е като временна променлива.
	struct QuadraticEquation {
		double a;
		double b;
		double c;
		double discriminant;
		double root1;
		double root2;
	};

	int run();

	bool hasRealRoots(const QuadraticEquation& eq);
	void findRoots(QuadraticEquation& eq);
	void setDiscriminant(QuadraticEquation& eq);
}