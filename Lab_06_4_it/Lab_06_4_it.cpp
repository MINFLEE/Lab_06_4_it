// Lab_06_4_it

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void InitArray(double* a, const int size);
void PrintArray(double* a, const int size);
double ProductOfPositiveElements(double* a, int size);
double SumBeforeMinElement(double* a, int size);
void SortEvenOddIndexes(double* a, int size);

int main()
{
    srand((unsigned)time(NULL));
    int n;
    cout << "n = ";
    cin >> n;
    cout << endl;

    double* a = new double[n];

    InitArray(a, n);
    cout << "Array:";
    PrintArray(a, n);
    cout << endl;

    // 1.1
    double product = ProductOfPositiveElements(a, n);
    cout << "Product of positive elements: " << product << endl;
    cout << endl;

    // 1.2
    double sum = SumBeforeMinElement(a, n);
    cout << "Sum of elements before the minimum: " << sum << endl;
    cout << endl;

    // 2
    SortEvenOddIndexes(a, n);
    cout << "Array after sorting even and odd  elements: ";
    PrintArray(a, n);

    return 0;
}

void InitArray(double* a, const int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 21 - 10;
    }
}

void PrintArray(double* a, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(4) << a[i] << " ";
    }
    cout << endl;
}

double ProductOfPositiveElements(double* a, int size)
{
    double product = 1;
    bool hasPositive = false;

    for (int i = 0; i < size; i++)
    {
        if (a[i] > 0)
        {
            product *= a[i];
            hasPositive = true;
        }
    }

    return hasPositive ? product : 0;
}

double SumBeforeMinElement(double* a, int size)
{
    double minElement = a[0];
    int minIndex = 0;

    for (int i = 1; i < size; i++)
    {
        if (a[i] < minElement)
        {
            minElement = a[i];
            minIndex = i;
        }
    }

    double sum = 0;
    for (int i = 0; i < minIndex; i++)
    {
        sum += a[i];
    }

    return sum;
}

void SortEvenOddIndexes(double* a, int size)
{
    for (int i = 0; i < size; i += 2)
    {
        for (int j = i + 2; j < size; j += 2)
        {
            if (a[i] > a[j])
            {
                double temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    for (int i = 1; i < size; i += 2)
    {
        for (int j = i + 2; j < size; j += 2)
        {
            if (a[i] > a[j])
            {
                double temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

