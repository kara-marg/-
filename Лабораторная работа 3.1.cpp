#include <iostream>
#include <math.h>
using namespace std;
//6. Визначити довжину кривої, заданої математичним виразом. Початкова і кінцева точка задаються користувачем. Формула 𝐿 = a∫b √𝑓′(𝑡)2 + 1

double f1(double x) //f1=x^2 - рівняння дуги кривої
{
    return x * x;
}

double f2(double x, double f1) //підінтегральний вираз
{
    return sqrt(f1 * f1 + 1);
}

int main()
{
    double a; //початкова точка
    cout << "a = ";
    cin >> a;
    double b; //кінцева точка
    cout << "b = ";
    cin >> b;
    double h = 0.001;
    double x1 = a + b;
    double f3 = (f1(x1 + h) - f1(x1 - h)) / (2 * h);
    double n = (b - a) / (h);
    double Integral = 0.0;
    double l;
    for (int i = 1; i <= n; i++)
    {
        l = Integral + h * f2((n + h * (i - 0.5)), f3);
        cout << "L = " << l << endl;
        cin >> l;
    }
}