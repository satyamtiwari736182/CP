// 1. You are given an array(arr) of integers.
// 2. You have to sort the given array in increasing order using quick-sort.

#include "../header.h"

int partition(int *arr, int left, int right, int pivot)
{
    int i = left, j = left;
    while (j <= right)
    {
        if (arr[j] > pivot)
            j++;
        else
            swap(arr[i], arr[j]), i++, j++;
    }
    return i - 1;
}

void quickSort(int *arr, int left, int right)
{
    if (left >= right)
        return;

    int pivot = arr[right];
    int pivot_idx = partition(arr, left, right, pivot);
    quickSort(arr, left, pivot_idx - 1);
    quickSort(arr, pivot_idx + 1, right);
}

void solve()
{
    int n, pivot, arr[100];
    cin >> n;
    rarr(arr, 0, n);
    // cin >> pivot;
    // int idx = partition(arr, 0, n - 1, pivot);
    quickSort(arr, 0, n - 1);
    cout << "\n*******\n";

    parr(arr, n);
}

int main()
{
    cout << "Hello world!\n";
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

/*
5
7 -2 4 1 3

*/