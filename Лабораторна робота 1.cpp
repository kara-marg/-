#include <iostream>
#include <string>
#include "Лабораторна робота 1.h"

using namespace std;
/* 6.Знайти всі прості числа вигляду 2^𝑛 − 1 (прості числа Мерсена) */
/*14. ● Реалізувати «довге» віднімання на множині натуральних чисел.*/

int main()
{
	NewFunction6();
	NewFunction14();
}

void NewFunction14()
{
	int firstNumber[4] = { 2,0,2,0 };
	int secondNumber[4] = { 1, 9, 9 ,9 };
	int firstNumberLenght = 4;
	int secondNumberLenght = 4;
	string result = "";
	int k = 1; // если k равно 1, то эти числа равны; если k равно 2, то второе число больше первого; если k равно 3, то первое число больше второго
	if (firstNumberLenght > secondNumberLenght)
	{
		k = 3;
	}
	else if (firstNumberLenght < secondNumberLenght)
	{
		k = 2;
	}
	else {
		for (int i = 0; i < firstNumberLenght; i++)
		{
			if (firstNumber[i] < secondNumber[i])
			{
				k = 2;
				break;
			}
			else if (firstNumber[i] > secondNumber[i])
			{
				k = 3;
				break;
			}

		}
	}

	if (k == 1)
	{
		cout << 0;
	}
	else if (k == 2)
	{
		for (int i = 1; i <= secondNumberLenght; i++)
		{
			int x = secondNumber[secondNumberLenght - i];


			if (firstNumberLenght - i >= 0) {
				int y = firstNumber[firstNumberLenght - i];
				if (x < 0) {
					secondNumber[secondNumberLenght - i - 1] --;
					x = x + 10;
				}

				int differents = x - y;
				if (differents < 0)
				{
					secondNumber[secondNumberLenght - i - 1] --;
					differents = differents + 10;
				}
				result = result + to_string(differents);
			}
			else {
				result = result + to_string(x);
			}



		}
		reverse(result.begin(), result.end());
		cout << "-" << result;
	}
	else if (k == 3) {
		for (int i = 1; i <= firstNumberLenght; i++)
		{
			int x = firstNumber[firstNumberLenght - i];
			if (secondNumber - i >= 0) {
				int y = secondNumber[secondNumberLenght - i];

				if (x < 0) {
					firstNumber[firstNumberLenght - i - 1] --;
					x = x + 10;
				}

				int differents = x - y;
				if (differents < 0)
				{
					firstNumber[firstNumberLenght - i - 1] --;
					differents = differents + 10;
				}

				result = result + to_string(differents);
			}
			else {
				result = result + to_string(x);
			}

		}
		reverse(result.begin(), result.end());
		cout << result;
	}
}

void NewFunction6()
{
	for (int n = 1; n <= 20; n++)
	{
		int p = (pow(2, n) - 1);
		bool isSimple = true;
		for (int i = 2; i <= (p / 2) + 1; i++)
		{
			if (p % i == 0)
			{
				isSimple = false;
				break;
			}
		}
		if (isSimple == true)
		{
			cout << p << endl;
		}

	}
}