#include <iostream>
#include <clocale>
#include "Лабораторная работа 2.h"
using namespace std;

/*6) Задаються коло та лінія. Якщо вони перетинаються, то вивести точки перетину.*/
//14) ● Дано опуклий багатокутник. Описати навколо нього коло.

int main()
{
    NewFunction6();
    NewFunction14();
}

void NewFunction6()
{
    // (x-a)^2 + (y-b)^2 = R^2 
    //  y = kx + c;
    // (k^2+1)x^2 + 2(kc-a-kb)x -R^2 + a^2 + b^2 + c^2 - 2bc = 0;
    // Ax^2 + Bx + C = 0
    setlocale(LC_CTYPE, "ukr");
    double a = 1.5;
    double b = 1.5;
    double R = 1.5;
    double k = 0;
    double c = 3;

    double A = (k * k + 1);
    double B = 2 * (k * c - a - b * k);
    double C = a * a + b * b + c * c - R * R - 2 * b * c;
    double D = pow(B, 2) - 4 * A * C;
    if (D > 0)
    {
        double x1 = (-B + sqrt(D)) / (2 * A);
        double x2 = (-B - sqrt(D)) / (2 * A);
        double y1 = k * x1 + c;
        double y2 = k * x2 + c;

        cout << "Задані коло та пряма пересікаються у двух точках: " << endl;
        cout << "x =" << x1 << " y=" << y1 << endl;
        cout << "x =" << x2 << " y=" << y2 << endl;
    }
    else if (D == 0)
    {
        double x1 = (-B + sqrt(D)) / (2 * A);
        double y1 = k * x1 + c;
        cout << "Задані коло та пряма дотикаються: " << endl;
        cout << "x =" << x1 << " y=" << y1 << endl;

    }
    else
    {
        cout << "Задані коло та пряма не мають спільних точок: " << endl;
    }
}

void NewFunction14()
{
    setlocale(LC_CTYPE, "rus");
    int num = 4; //Кількість сторін
    double* x = new double[num];
    double* y = new double[num];
    for (int i = 0; i < num; i++)
    {
        cout << "Координати вершин: ";
        cin >> x[i] >> y[i];
    }
    double ox; //Координати x центра сторони
    double oy; //Координати y центра сторони

    ox = ((x[1] + x[3]) / 2);
    oy = ((y[1] + y[3]) / 2);
    cout << "(" << ox << ";" << oy << ")" << endl; //центр кола
    double d; //діаметр
    d = sqrt((pow((x[3] - x[1]), 2)) + (pow((y[3] - y[1]), 2)));
    double r;
    r = d / 2;
    cout << "R= " << r << endl;
}