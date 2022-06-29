// 1. You are given an array(arr) of integers.
// 2. You have to sort the given array in increasing order using bubble sort.

#include "../header.h"

void bubbleSort(vi &arr)
{
    for (int pass = 0; pass < arr.size() - 1; pass++)
        for (int i = 0; i < arr.size() - 1 - pass; i++)
            if (arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    bubbleSort(arr);
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

