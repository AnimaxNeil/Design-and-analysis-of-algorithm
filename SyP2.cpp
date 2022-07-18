// Implement Heap Sort(The program should report the number of comparisons)

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

int max_heapify(int arr[], int size, int root)
{
    int max = root, left = root * 2 + 1, right = root * 2 + 2, cmp = 0;
    if (left < size && arr[left] > arr[max])
    {
        max = left;
    }
    cmp++;
    if (right < size && arr[right] > arr[max])
    {
        max = right;
    }
    cmp++;
    if (max != root)
    {
        int temp = arr[root];
        arr[root] = arr[max];
        arr[max] = temp;
        cmp += max_heapify(arr, size, max);
    }
    return cmp;
}

int heap_sort(int arr[], int size)
{
    int cmp = 0;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        cmp += max_heapify(arr, size, i);
    }
    int temp;
    for (int i = size - 1; i >= 1; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        cmp += max_heapify(arr, i, 0);
    }
    return cmp;
}

void test_heap_sort()
{
    int arr[] = {3, 6, -7, 2, 14, -21, 33, -342, 765, 123, 720, 22, 11, 23, -32, 0, -169, 77, 92};
    const int size = (int)(sizeof(arr)) / (int)(sizeof(arr[0]));
    cout << "\nUnsorted :\t";
    print(arr, size);
    int cmp = heap_sort(arr, size);
    cout << "\nAfter Heap Sort :\t";
    print(arr, size);
    cout << "Number of comparisons :\t" << cmp << "\n";
}

int main()
{
    test_heap_sort();
    cin.get();
    return 0;
}
