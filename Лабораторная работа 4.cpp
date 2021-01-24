#include <iostream>
using namespace std;

/*Вивести на екран всі перестановки чисел від 1 до N, при яких ∀i a[i]≠i*/

// получить массив чисел от 1 до N
int* getAllNumbers(int n) {
	int* res = new int[n];

	for (int i = 1; i <= n; i++) {
		res[i - 1] = i;
	}

	return res;
}

// получить массив чисел без указаного числа (exceptNumber), startArray = начальный масив 
int* getArrayNumberExceptNumber(int* startArray, int startArrayLength, int exceptNumber) {

	int* res = new int[startArrayLength - 1];
	int j = 0;


	for (int i = 0; i < startArrayLength; i++) {
		if (startArray[i] != exceptNumber) {
			res[j] = startArray[i];
			j++;
		}
	}

	return res;
}

//находим факториал
int calcFact(int n) {
	int res = 1;
	for (int i = 1; i <= n; i++) {
		res = res * i;
	}
	return res;
}


int* joinNumberAndArray(int number, int* arr, int length) {
	int* res = new int[length + 1];
	res[0] = number;
	for (int i = 0; i < length; i++) {
		res[i + 1] = arr[i];
	}

	return res;
}


int** permutations(int* numbers, int length) {
	int** resultList;
	resultList = new int* [calcFact(length)]; // todo count


  // умова виходу 
	if (length == 1) {
		resultList[0] = numbers;
		return resultList;
	}
	int currentNumber;
	int j = 0;

	for (int i = 0; i < length; i++)
	{
		currentNumber = numbers[i];

		int* subList = getArrayNumberExceptNumber(numbers, length, currentNumber);
		int** subPermutations = permutations(subList, length - 1);
		int subLength = calcFact(length - 1);
		for (int k = 0; k < subLength; k++)
		{
			resultList[j] = joinNumberAndArray(currentNumber, subPermutations[k], length - 1);
			j++;
		}
	}

	return resultList;
}
//перестановка
void printPermutation(int* permutation, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << permutation[i] << " ";
	}
	cout << endl;
}
//кінцева перестановка
void printFilteredPermutations(int** allPermutations, int countOfPermutations, int numberCount)
{
	for (int i = 0; i < countOfPermutations; i++)
	{
		int* permutation = allPermutations[i];
		bool isApplyFilter = true;

		for (int j = 0; j < numberCount; j++)
		{
			if (permutation[j] == j + 1)
			{
				isApplyFilter = false;
				break;
			}
		}

		if (isApplyFilter)
		{
			printPermutation(permutation, numberCount);
		}
	}
}


int main()
{
	int n;
	cout << "N = ";
	cin >> n;

	int* allNumbers = getAllNumbers(n);
	int** allPermutations = permutations(allNumbers, n);
	int countOfAllPermutations = calcFact(n);

	for (int i = 0; i < countOfAllPermutations; i++)
	{
		printPermutation(allPermutations[i], n);
	}

	cout << "_______________________________________________" << endl;

	printFilteredPermutations(allPermutations, countOfAllPermutations, n);

}