// 1. You are given an array(arr) of integers.
// 2. You have to sort the given array in increasing order using insertion sort.
#include "../header.h"

void insertionSort(vi &arr)
{
    for (int pass = 0; pass < arr.size() - 1; pass++)
        for (int i = pass + 1; i > 0; i--)
            if (arr[i - 1] > arr[i])
                swap(arr[i - 1], arr[i]);
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    insertionSort(arr);
    parr(arr, n);
    cout << endl;
}

int main()
{
    cout << "Hello world!\n";
    int t = 1;
    cin >> t;
    test(t)
        solve();
    return 0;
}

/*
2
5
7 -2 4 1 3

6
3 2 1 5 6 4

*/