#include <iostream>
#include <cmath>

// Задачата не покрива условието, тъй като липсва цялостна употреба на структури.
// Това на контролно или изпит би коствало цялата задача, тъй като не се спазва условието.

void printArr(double* arr, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void readTriangles(int n, int** triangles) {
	for (int i = 0; i < n; i++) {
		for (int point = 0; point < 3; point++) {
			int x;
			int y;

			std::cin >> x;
			std::cin >> y;

			while (x < -100 || y < -100 || x>100 || y >100) {
				std::cout << "Invalid input!!! \n x,y must be -100<= x,y <=100" << std::endl;

				std::cin >> x;
				std::cin >> y;
			}

			triangles[i][point * 2] = x;
			triangles[i][point * 2+1] = y;

		}
	}
}

// std::abs is a thing!
// Можеш да го използваш.
int getModul(int x) {
	if (x < 0) {
		x *= -1;
	}
	return x;
}

double getSurfaceAreaOfTriangle(int* points) {
	


	int a1 = getModul(points[0] - points[2]);
	int a2 = getModul(points[1] - points[3]);
	double a = sqrt(a1 * a1 + a2 * a2);
	

	int b1 = getModul(points[2] - points[4]);
	int b2 = getModul(points[3] - points[5]);
	double b = sqrt(b1 * b1 + b2 * b2);


	int c1 = getModul(points[4] - points[0]);
	int c2 = getModul(points[5] - points[1]);
	double c = sqrt(c1 * c1 + c2 * c2);

	double p = (a + b + c) / 2;

	double s = sqrt(p*(p-a)*(p-b)*(p-c));

	return s;

}

double* getSurfacesOfTriangles(int** triangles, int n) {
	// Липсва std::nothrow!
	// Това може да доведе до потенциален crash и от там редица други проблеми.
	double* surfaces = new double[n];
	for (int i = 0; i < n; i++) {
		surfaces[i] = getSurfaceAreaOfTriangle(triangles[i]);
	}
	return surfaces;
}

// По условие се изискваше да се въведат и сортират цели триъгълници, а не просто лицата им.
// Това е същото като да ти дам за задача да сортираш шишета на рафт спрямо височината им и ти се върнеш с един лист,
// на който си написал височините в сортиран ред. Реално заобикаляш проблема.
// За такива уточнения на контролно и изпит е напълно възможно да ти се анулира задачата, защото не е по условието.
void sortSurfaces(double* surfaces, int n) {
	for (int i = n; i >= 0; i--) {
		for (int j = 0; j < i-1; j++) {
			if (surfaces[j] > surfaces[j+1]) {
				double temp = surfaces[j];
				surfaces[j] = surfaces[j + 1];
				surfaces[j+1] = temp;

			}
		}
	}
}

int main1() {
	int n;
	std::cin >> n;
	while (n < 1 || n>1000) {
		std::cout << "Invalid input!!! \n n must be 1<=n<=1000" << std::endl;
		std::cin >> n;

	}

	// Липсва std::nothrow, като аргумент на new, което може да доведе до crash и от там memory leaks.
	int** triangles = new int*[n];
	// Липсва валидация на указателят triangles.
	// Ако new не успее да го задели правилно ще имаш nullptr.
	// Когато се опитваш да адресираш nullptr получаваш runtime грешка.
	for (int i = 0; i < n; i++) {
		// Липсва std::nothrow, като аргумент на new!
		triangles[i] = new int[6];
		// Нямаш валидация дали заделянето е било успешно.
	}

	readTriangles(n, triangles);
	
	double* surfaces = getSurfacesOfTriangles(triangles,n);
	sortSurfaces(surfaces, n);

	printArr(surfaces , n);


	for (int i = 0; i < n; i++) {
		delete[] triangles[i];
	}
	delete[] triangles;
	delete[] surfaces;
	return 0;
}