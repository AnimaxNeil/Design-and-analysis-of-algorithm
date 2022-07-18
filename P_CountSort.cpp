// Count Sort

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

void count_sort(int arr[], int size)
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
    int sizeC = max - min + 1;
    int *arrC = new int[sizeC];
    for (int i = 0; i < sizeC; i++)
    {
        arrC[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        arrC[arr[i]]++;
    }
    for (int i = 1; i < sizeC; i++)
    {
        arrC[i] += arrC[i - 1];
    }
    int *arrS = new int[size];
    for (int i = size - 1; i >= 0; i--)
    {
        arrS[--arrC[arr[i]]] = arr[i] + min;
    }
    for (int i = 0; i < size; i++)
    {
       arr[i] = arrS[i];
    }
    delete[] arrC;
}

void test_count_sort()
{
    int arr[] = {3, 6, -7, 2, 14, -21, 33, -342, 765, 123, 720, 22, 11, 23, -32, 0, -169, 77, 92};
    const int size = (int)(sizeof(arr)) / (int)(sizeof(arr[0]));
    cout << "Unsorted :\t";
    print(arr, size);
    count_sort(arr, size);
    cout << "\nAfter Count Sort :\t";
    print(arr, size);
}

int main()
{
    test_count_sort();
    cin.get();
    return 0;
}

