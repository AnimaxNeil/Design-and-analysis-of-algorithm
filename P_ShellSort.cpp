// Shell Sort

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

void shell_sort(int arr[], int size)
{
    int temp, j;
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void test_shell_sort()
{
    int arr[] = {3, 6, -7, 2, 14, -21, 33, -342, 765, 123, 720, 22, 11, 23, -32, 0, -169, 77, 92};
    const int size = (int)(sizeof(arr)) / (int)(sizeof(arr[0]));
    cout << "Unsorted :\t";
    print(arr, size);
    shell_sort(arr, size);
    cout << "\nAfter Shell Sort :\t";
    print(arr, size);
}

int main()
{
    test_shell_sort();
    cin.get();
    return 0;
}
