#include <iostream>
using namespace std;
#include <math.h>
#include <iomanip>

double f(double x)
{
	return acos(x) - sqrt(1 - 0.3 * pow(x, 3));
}
double f1(double x)
{
	return ((9 * x * x * pow(10 - 10 * x, 1 / 2) - 20 * \
		pow(10 - 3 * pow(x, 3), 1 / 2)) / (20 * pow(10 - 10 * x * x - 3 * pow(x, 2) - 3 * pow(x, 5), 1 / 2)));
}
double f2(double x)
{
	return acos(x) - sqrt(1 - 0.3 * pow(x, 3)) / ((9 * pow(x, 2)) / \
		(2 * sqrt(100 - 30 * pow(x, 3))) - 1 / sqrt(1 - pow(x, 2)));
}
double foundx(double x, double(*)(double), double(*)(double))
{
	return x - (f(x) / f1(x));
}
double solution(double(*)(double), double(*)(double), double(*)(double), int a, int b, double accuracy)
{
	double x0, x1 = 0;
	int iterator = 0;
	if (f2(a) * f1(a) > 0)
		x0 = a;
	else
		x0 = b;
	while (abs(x1 - x0) > accuracy)
	{
		x0 = x1;
		x1 = x0 - (f(x0) / f1(x0));
		iterator++;
		cout << "итерация № " << iterator << " x0 = " << x0 << " x1 = " << x1 << " приближение = " << setprecision(10) << accuracy << endl;
	}
	return x1;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a = 0, b = 1;
	cout<< solution(f, f1, f2, a, b, 1e-10);
	return 0;
}
