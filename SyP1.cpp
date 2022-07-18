// i. Implement Insertion Sort (The program should report the number of comparisons)
// ii.Implement Merge Sort(The program should report the number of comparisons)

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

int insertion_sort(int arr[], int size)
{
    int key, j, cmp = 0;
    for (int i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            cmp++;
        }
        cmp++;
        arr[j + 1] = key;
    }
    return cmp;
}

int merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0, sizeM = high - low + 1, cmp = 0;
    int *arrM = new int[sizeM];
    while (i <= mid && j <= high)
    {
        arrM[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
        cmp++;
    }
    cmp++;
    while (i <= mid)
    {
        arrM[k++] = arr[i++];
    }
    while (j <= high)
    {
        arrM[k++] = arr[j++];
    }
    k = 0;
    for (i = low; i <= high; i++)
    {
        arr[i] = arrM[k++];
    }
    delete[] arrM;
    return cmp;
}

int perform_merge_sort(int arr[], int low, int high, int cmp)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        cmp = perform_merge_sort(arr, low, mid, cmp);
        cmp = perform_merge_sort(arr, mid + 1, high, cmp);
        cmp += merge(arr, low, mid, high);
    }
    return cmp;
}

int merge_sort(int arr[], int size)
{
    return perform_merge_sort(arr, 0, size - 1, 0);
}

void test_insertion_sort()
{
    int arr[] = {3, 6, -7, 2, 14, -21, 33, -342, 765, 123, 720, 22, 11, 23, -32, 0, -169, 77, 92};
    const int size = (int)(sizeof(arr)) / (int)(sizeof(arr[0]));
    cout << "\nUnsorted :\t";
    print(arr, size);
    int cmp = insertion_sort(arr, size);
    cout << "\nAfter Insertion Sort :\t";
    print(arr, size);
    cout << "Number of comparisons :\t" << cmp << "\n";
}

void test_merge_sort()
{
    int arr[] = {3, 6, -7, 2, 14, -21, 33, -342, 765, 123, 720, 22, 11, 23, -32, 0, -169, 77, 92};
    const int size = (int)(sizeof(arr)) / (int)(sizeof(arr[0]));
    cout << "\nUnsorted :\t";
    print(arr, size);
    int cmp = merge_sort(arr, size);
    cout << "\nAfter Merge Sort :\t";
    print(arr, size);
    cout << "Number of comparisons :\t" << cmp << "\n";
}

int main()
{
    test_insertion_sort();
    test_merge_sort();
    cin.get();
    return 0;
}
