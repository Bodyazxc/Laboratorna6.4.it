#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cmath>

using namespace std;

void create(int* arr, int SIZE, int MIN, int MAX)
{
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % (MAX - MIN + 1) + MIN;
    }
}

void Print(int* arr, int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        cout << setw(10) << arr[i];
    cout << endl;
}

int sum(int* arr, int SIZE)
{
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] > 0)
        {
            sum += arr[i];
        }
    }
    return sum;
}

int product(int* arr, int SIZE)
{
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 1; i < SIZE; i++)
    {
        if (abs(arr[i]) < abs(arr[minIndex]))
        {
            minIndex = i;
        }
        if (abs(arr[i]) > abs(arr[maxIndex]))
        {
            maxIndex = i;
        }
    }

    int result = 1;
    bool hasElements = false;

    if (minIndex < maxIndex)
    {
        for (int i = minIndex + 1; i < maxIndex; i++)
        {
            result *= arr[i];
            hasElements = true;
        }
    }
    else
    {
        for (int i = maxIndex + 1; i < minIndex; i++)
        {
            result *= arr[i];
            hasElements = true;
        }
    }

    if (!hasElements)
    {
        return 0;
    }

    return result;
}

void sort(int* arr, int SIZE)
{
    int* o = new int[SIZE];
    int oddCount = 0;

    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] % 2 != 0)
        {
            o[oddCount] = arr[i];
            oddCount++;
        }
    }

    if (oddCount == 0)
    {
        delete[] o;
        return;
    }

    for (int i = 0; i < oddCount - 1; i++)
    {
        for (int j = i + 1; j < oddCount; j++)
        {
            if (o[i] < o[j])
            {
                int temp = o[i];
                o[i] = o[j];
                o[j] = temp;
            }
        }
    }

    int oIndex = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[i] % 2 != 0)
        {
            arr[i] = o[oIndex];
            oIndex++;
        }
    }

    delete[] o;
}

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int SIZE;
    cout << "Введіть розмір масиву (SIZE): "; cin >> SIZE;
    int MIN = -15;
    int MAX = 25;
    int* arr = new int[SIZE];

    create(arr, SIZE, MIN, MAX);

    Print(arr, SIZE);
    cout << endl;
    cout << "Сума додатніх елементів масиву: " << sum(arr, SIZE) << endl;
    cout << "Добуток елементів масиву  між максимальним  та мінімальним за модулем елементами: " << product(arr, SIZE) << endl;
    sort(arr, SIZE);
    cout << endl;
    Print(arr, SIZE);
    delete[] arr;
    return 0;
}
