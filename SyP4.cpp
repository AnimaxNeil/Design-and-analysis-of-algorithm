// Implement Radix Sort

#include <iostream>
using namespace std;

void print(int arr[], int size)
{
    using namespace std;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "\n";
}

void radix_sort(int arr[], int size)
{
    if (size <= 0)
    {
        return;
    }
    int min = arr[0], max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i] - min;
    }
    int arrC[10];
    int *arrS = new int[size];
    for (int pos = 1; (max - min) / pos > 0; pos *= 10)
    {
        for (int i = 0; i < 10; i++)
        {
            arrC[i] = 0;
        }
        for (int i = 0; i < size; i++)
        {
            arrC[(arr[i] / pos) % 10]++;
        }
        for (int i = 1; i < 10; i++)
        {
            arrC[i] += arrC[i - 1];
        }
        for (int i = size - 1; i >= 0; i--)
        {
            arrS[--arrC[(arr[i] / pos) % 10]] = arr[i];
        }
        for (int i = 0; i < size; i++)
        {
            arr[i] = arrS[i];
        }
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i] + min;
    }
    delete[] arrS;
}

void test_count_sort()
{
    int arr[] = {3, 6, -7, 2, 14, -21, 33, -342, 765, 123, 720, 22, 11, 23, -32, 0, -169, 77, 92};
    const int size = (int)(sizeof(arr)) / (int)(sizeof(arr[0]));
    cout << "Unsorted :\t";
    print(arr, size);
    radix_sort(arr, size);
    cout << "\nAfter Count Sort :\t";
    print(arr, size);
}

int main()
{
    test_count_sort();
    cin.get();
    return 0;
}

