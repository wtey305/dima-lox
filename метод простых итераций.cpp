// ньютон.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include <math.h>
#include <iomanip>
#include <iomanip>

double f(double x)
{
	return acos(x) - sqrt(1 - 0.3 * pow(x, 3));
}
double fi(double x)
{
	return cos(sqrt(1 - 0.3 * pow(x, 3)));
}
double fi1(double x)
{
	return (9 * sqrt(10) * pow(x, 2) * sin(sqrt((10 - 3 * pow(x, 3)) / 10))) / (20 * sqrt(10 - 3 * pow(x, 3)));
}
double solution(double(*)(double), double(*)(double), double(*)(double), int a, int b, double accuracy)
{
	double x0, x1;
	int iterator = 1;
	if (abs(fi1(a)) < 1)
		x0 = a;
	else
		x0 = b;
	x1 = fi(x0);
	while (abs(x1 - x0) > accuracy)
	{
		cout << "итерация № " << iterator << " x0 = " << x0 << " x1 = " << x1 << " приближение = " << setprecision(10) << abs(x1 - x0) << endl;
		x0 = x1;
		x1 = fi(x0);
		iterator++;
	}
	return x1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a = 0, b = 1;
	cout <<"корень уравнения: " << solution(f, fi, fi1, a, b, 1e-10);
	return 0;
}
