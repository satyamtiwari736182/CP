// 1. You are given an array(arr) of integers.
// 2. You have to sort the given array in increasing order using selection sort.

#include "../header.h"

void selectionSort(vi &arr)
{
    for (int pass = 0; pass < arr.size() - 1; pass++)
    {
        int min_val = pass;
        for (int i = pass + 1; i < arr.size(); i++)
            if (arr[min_val] > arr[i])
                min_val = i;
        swap(arr[pass], arr[min_val]);
    }
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    selectionSort(arr);
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