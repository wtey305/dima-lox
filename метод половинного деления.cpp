
#include <math.h> 
#include <iostream> 
#include <iomanip> 
using namespace std;

double f(double x)
{
    return acos(x) - sqrt(1 - 0.3 * pow(x, 3));
}

double half(double a, double b, double accuracy)
{
    int iterator = 1;
    double x0;

    while (abs(b - a) > accuracy)
    {
        x0 = (a + b) / 2;
        cout << "итерация № " << iterator << " a = " << a << " b = " << b << " x0 = " << x0 << " приближение = " << setprecision(10) << abs(b - a) << endl;

        if (f(a) * f(x0) < 0) 
        {
            b = x0; 
        }
        else
        {
            a = x0; 
        }

        iterator++;
    }

    return (a + b) / 2; 
}

int main()
{
    setlocale(LC_ALL, "russian");
    double a = -1, b = 1;
    cout << "корень уравнения = " << half(a, b, 1e-10) << endl;
    return 0;
}