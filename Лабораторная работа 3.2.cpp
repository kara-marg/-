#include <iostream>
using namespace std;

//20.(*) Дано функцію 𝑓(𝑥), що всюди на [a,b] має похідну. Визначити всі нулі функції на відрізку[a, b]
int main()
{
	// y=x^3-4x - функція
	// x=0, x=2, x=-2
	setlocale(LC_ALL, "RUS");
	double a;
	cout << "a = ";
	cin >> a;
	double b;
	cout << "b = ";
	cin >> b;
	double x;
	double x1;
	double x2;
	if ((-2 < a) && (a < 0) && (0 < b) && (b < 2))
	{
		x = 0;
		cout << "x = " << x << endl;
	}
	else if ((-100 < a) && (a < -2) && (2 < b) && (b < 100))
	{
		x = 0;
		x1 = -2;
		x2 = 2;
		cout << "x = " << x << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}
	else if ((-100 < a) && (a < -2) && (0 < b) && (b < 2))
	{
		x1 = 0;
		x2 = -2;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}
	else if ((-2 < a) && (a < 0) && (2 < b) && (b < 100))
	{
		x1 = 0;
		x2 = 2;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}
	else
	{
		cout << "Function zeros are missing" << endl;
	}
}