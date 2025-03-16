#include <iostream>
#include <cmath>


struct QuadraticEquation
{
	double a, b, c;

	// Отново, нека не избързваме с материала.
	double discriminant()
	{
		return pow(b, 2) - 4 * a * c;
	}

	void swap(double* a, double* b)
	{
		double temp = *a;
		*a = *b;
		*b = temp;
	}

	void solve()
	{
		double d = discriminant();

		if (d<0)
		{
			std::cout << "The equation does not have real solutions!"<<std::endl;
		}
		else if (d==0)
		{
			double x = -b / (2 * a);
			std::cout << x << std::endl;
		}
		else
		{
			double x1 = ( - b-sqrt(d) )/ (2 * a);
			double x2 = ( - b+sqrt(d) )/ (2 * a);

			if (x1>x2)
			{
				swap(&x1,&x2);
			}
			std::cout << x1 <<" "<< x2 << std::endl;
		}
	}

};


int main()
{
	double a, b, c;
	std::cin >> a >> b >> c;

	if (a<-100 || b<-100 || c<-100 ||
		a>100 ||b>100 ||c>100)
	{
		std::cout << "Imvalid input!";
		return 1;
	}
	
	QuadraticEquation equation = { a,b,c };

	equation.solve();
	
	
	return 0;
}
