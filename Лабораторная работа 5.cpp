#include <iostream>
using namespace std;


long polishNotation()
{
	while (cin.peek() == ' ')
		cin.get();

	switch (cin.peek())
	{
	case'-':
		cin.get();
		return polishNotation() - polishNotation();
	case'+':
		cin.get();
		return polishNotation() + polishNotation();
	case'*':
		cin.get();
		return polishNotation() * polishNotation();
	case'/':
		cin.get();
		return polishNotation() / polishNotation();
	case'-+':
		cin.get();
		return polishNotation() - polishNotation() + polishNotation();
	case'+-':
		cin.get();
		return polishNotation() + polishNotation() - polishNotation();
	case'*/':
		cin.get();
		return polishNotation() * polishNotation() / polishNotation();
	case'/*':
		cin.get();
		return polishNotation() / polishNotation() * polishNotation();
	case'+*':
		cin.get();
		return polishNotation() * polishNotation() + polishNotation();
	case'*+':
		cin.get();
		return polishNotation() * polishNotation() + polishNotation();
	case'*-':
		cin.get();
		return polishNotation() * polishNotation() - polishNotation();
	case'-*':
		cin.get();
		return polishNotation() * polishNotation() - polishNotation();
	case'/-':
		cin.get();
		return polishNotation() / polishNotation() - polishNotation();
	case'-/':
		cin.get();
		return polishNotation() / polishNotation() - polishNotation();
	case'+/':
		cin.get();
		return polishNotation() / polishNotation() + polishNotation();
	case'/+':
		cin.get();
		return polishNotation() / polishNotation() + polishNotation();
	default:
	{
		long value;
		cin >> value;
		return value;
	}
	}
}
int main()
{
	cout << polishNotation() << endl;
	return 0;
}