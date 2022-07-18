// Implement Randomized Quick sort (The program should report the number of comparisons)

#include <iostream>
#include <ctime>
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

int *partition(int arr[], int low, int high)
{
    int pivot = low;
    int l = low + 1, h = high, temp, cmp = 0;
    while (l < h)
    {
        while (arr[l] <= arr[pivot] && l < high)
        {
            l++;
        }
        cmp++;
        while (arr[h] > arr[pivot] && h > low)
        {
            h--;
        }
        cmp++;
        if (l < h)
        {
            temp = arr[l];
            arr[l] = arr[h];
            arr[h] = temp;
        }
    }
    temp = arr[h];
    arr[h] = arr[pivot];
    arr[pivot] = temp;
    pivot = h;
    return new int[2]{pivot, cmp};
}

int *random_partition(int arr[], int low, int high)
{
    int random = low + rand() % (high - low);
    int temp = arr[low];
    arr[low] = arr[random];
    arr[random] = temp;
    return partition(arr, low, high);
}

int perform_quick_sort(int arr[], int low, int high, int cmp)
{
    if (low < high)
    {
        int *returnArr = random_partition(arr, low, high);
        int pivot = returnArr[0];
        cmp += returnArr[1];
        delete[] returnArr;
        cmp = perform_quick_sort(arr, low, pivot - 1, cmp);
        cmp = perform_quick_sort(arr, pivot + 1, high, cmp);
    }
    return cmp;
}

int quick_sort(int arr[], int size)
{
    return perform_quick_sort(arr, 0, size - 1, 0);
}

void test_quick_sort()
{
    int arr[] = {3, 6, -7, 2, 14, -21, 33, -342, 765, 123, 720, 22, 11, 23, -32, 0, -169, 77, 92};
    const int size = (int)(sizeof(arr)) / (int)(sizeof(arr[0]));
    cout << "Unsorted :\t";
    print(arr, size);
    int cmp = quick_sort(arr, size);
    cout << "\nAfter Quick Sort :\t";
    print(arr, size);
    cout << "Number of comparisons :\t" << cmp << "\n";
}

int main()
{
    srand(time(NULL));
    test_quick_sort();
    cin.get();
    return 0;
}
