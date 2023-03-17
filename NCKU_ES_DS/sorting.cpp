#include <iostream>
#include <vector>
using namespace std;

void swap(int & a, int & b);
void BubbleSort(int *arr, int length);
void QuickSort(int *arr, int left, int right);
void Merge(int *arr, int front, int mid, int end);
void MergeSort(int *arr, int front, int end);

int main()
{
    int array[10] = {3, 2, 1, 20, 5, 6, 8, 11, 23, 4};
    for (int i = 0; i < 10; i++)
        cout << array[i] << ' ';
    cout << endl;

    BubbleSort(array, 10);
    // QuickSort(array, 0, 9);
    // MergeSort(array, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << array[i] << ' ';
}

void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        bool flag = true;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = false;
            }
        }
        if (flag)
            return;
    }
}

void QuickSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int pivot = arr[left], i = left, j = right + 1;
        do
        {
            do i++; while (i <= right && arr[i] < pivot);
            do j--; while (j > left && arr[j] > pivot);
            if (i < j)
                swap(arr[j], arr[i]);
        } while (i < j);
        swap(arr[j], arr[left]);
        QuickSort(arr, left, j - 1);
        QuickSort(arr, j + 1, right);
    }
}

void Merge(int *arr, int front, int mid, int end)
{
    int *Lstring = new int(mid - front + 2);
    int *Rstring = new int(end - mid + 1);
    for (int index = 0; index <= mid - front; index++)
        Lstring[index] = arr[index + front];
    for (int index = 0; index <= end - mid - 1; index++)
        Rstring[index] = arr[index + mid + 1];
    Lstring[mid - front + 1] = INT32_MAX;
    Rstring[end - mid] = INT32_MAX;

    int leftidx = 0, rightidx = 0;
    for (int i = front; i <= end; i++)
    {
        if (Lstring[leftidx] > Rstring[rightidx])
            arr[i] = Rstring[rightidx++];
        else
            arr[i] = Lstring[leftidx++];
    }
    delete Lstring;
    delete Rstring;
}

void MergeSort(int *arr, int front, int end)
{
    if (front < end)
    {
        int mid = (front + end)/2;
        MergeSort(arr, front, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, front, mid, end);
    }
}