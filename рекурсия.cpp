using namespace std;
#include <iostream>
#include <math.h>
double factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}
double recursia(double x, int n)
{
    if (n == 0)
    {
        cout << "член прогрессии = 1" << endl;
        return 1;
    }
    else
    {
        cout << "член прогрессии = " << pow(x, 2 * n) / factorial(n * 2) << endl;
        return pow(x, 2 * n) / factorial(n * 2) + recursia(x, n - 1);
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    double x;
    cout << "введите n и x" << endl;
    cin >> n >> x;
    cout << "результат суммирования " << recursia(x, n) << endl;
    return 0;
}

