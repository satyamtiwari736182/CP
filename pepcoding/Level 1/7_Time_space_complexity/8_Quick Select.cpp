// 1. You are given an array(arr) of integers.
// 2. You have to find the k-th smallest element in the given array using the quick-select algorithm.

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

int quickSelect(int *arr, int left, int right, int k)
{
    if (left >= right)
        return -1;

    int pivot = arr[right];
    int pivot_idx = partition(arr, left, right, pivot);
    if (pivot_idx == k)
        return arr[k];
    if (k > pivot_idx)
        quickSelect(arr, pivot_idx + 1, right, k);
    else
        quickSelect(arr, left, pivot_idx - 1, k);
}

void solve()
{
    int n, k, arr[100];
    cin >> n;
    rarr(arr, 0, n);
    cin >> k;
    // int idx = partition(arr, 0, n - 1, pivot);
    int val = quickSelect(arr, 0, n - 1, k - 1);
    cout << "\n*******\n"
         << val << endl;

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
3
*/