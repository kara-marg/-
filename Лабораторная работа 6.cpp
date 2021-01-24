#include <iostream>
#include <fstream>
using namespace std;

/*2) Вивести текст на екран, прибравши зайві пробіли та вирівнявши текст по лівому
краю. Абзаци мають виділятися абзацним відступом.*/
int main()
{
	char filename[80] = "D:\\Прога\\Лабораторные работы\\Лабораторная работа 6\\data.txt ";
	ifstream input_file(filename);
	char line[200];
	while (!input_file.eof())
	{
		input_file.getline(line, sizeof(line));
		for (int j = 0; j < strlen(line); j++)
		{
			if (line[j] == ' ')
			{
				int x(1);
				while (line[j + 1] == ' ')
				{
					x++;
					int i = j + 1;
					if (line[0] != ' ')
					{
						for (int k = 0; k < i; k++)
						{
							cout << line[k];
						}
					}
					for (int p = i + x + 1; p < strlen(line); p++)
					{
						cout << line[p];
					}
					cout << endl; j = strlen(line) - 1;
					break;
				}
			}
		}
	}
}