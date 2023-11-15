// lab6.4.2.cpp
// Кузьмінська Єлизавета
// Лабораторна робота № 6.4
//  Опрацювання та впорядкування одновимірних динамічних масивів
// Варіант 10
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* c, const int n, const int Low, const int High, int i)
{
    c[i] = Low + rand() % (High - Low + 1);
    if (i < n - 1)
        Create(c, n, Low, High, i + 1);
}
void Print(int* c, const int n, int i)
{
    cout << setw(4) << c[i];
    if (i < n - 1)
        Print(c, n, i + 1);
    else
        cout << endl;
}
int Min(int* a, const int n, int min, int i) {
    if (abs(a[i]) < min)
        min = abs(a[i]);

    if (i < n - 1)
        return Min(a, n, min, i + 1);
    else
        return min;
}
int FindIndexFirstZeroElement(int* a, const int size, int i)
{
    if (a[i] == 0)
        return i;
    if (i < size - 1)
        return FindIndexFirstZeroElement(a, size, i + 1);
    else
        return -1;
}
int Sum(int* a, const int n, int i, int S) {
    S += abs(a[i]);

    if (i < n - 1)
        return Sum(a, n, i + 1, S);
    else
        return S;
}
void oddElementsToTheLeftRecursive(int* b, int* a, const int size, int i, int j)
{
    if (i < size) {
        if (i % 2 == 0) {
            a[j] = b[i];
            oddElementsToTheLeftRecursive(b, a, size, i + 1, j + 1);
        }
        else {
            oddElementsToTheLeftRecursive(b, a, size, i + 1, j);
        }
    }
}
void evenElementsToTheRightRecursive(int* b, int* a, const int size, int i, int j)
{
    if (i < size) {
        if (i % 2 != 0) {
            a[j] = b[i];
            evenElementsToTheRightRecursive(b, a, size, i + 1, j + 1);
        }
        else {
            evenElementsToTheRightRecursive(b, a, size, i + 1, j);
        }
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int n;
    cout << "n="; cin >> n;
    int* b = new int[n];
    int Low;
    cout << "Low="; cin >> Low;
    int High;
    cout << "High="; cin >> High;

    Create(b, n, Low, High, 0);
    Print(b, n, 0);

    cout << " min = " << Min(b, n, abs(b[0]), 0) << endl;
    int FirstZeroI = FindIndexFirstZeroElement(b, n, 0);
    if (FirstZeroI != -1)
        cout << " Sum = " << Sum(b, n, FirstZeroI + 1, 0) << endl;
    else
        cout << " Error: 0 is not found!" << endl;

    int* a = new int[n];
    a[0] = b[0];
    int j = 1;
    oddElementsToTheLeftRecursive(b, a, n, 1, j);
    if (n % 2 == 0)
        j = n / 2;
    else
        j = n / 2 + 1;
    evenElementsToTheRightRecursive(b, a, n, 1, j);
    b = a;
    Print(b, n, 0);
    delete[] a;
    return 0;
}
