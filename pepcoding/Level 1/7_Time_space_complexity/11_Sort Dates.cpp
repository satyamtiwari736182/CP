// 1. You are given an array(arr) of different dates in format DD-MM-YYYY.
// 2. You have to sort these dates in increasing order.

#include "../header.h"
void prefixSum(vi &arr)
{
    for (int i = 1; i < arr.size(); i++)
        arr[i] += arr[i - 1];
}

void countSort(vi &arr, int exp, int div, int range)
{
    // int mx = 9;
    int mn = 0;
    // int range = mx - mn + 1;
    vi freq(range);
    for (int i = 0; i < arr.size(); i++)
        freq[((arr[i] - mn) / exp) % div]++;

    prefixSum(freq);

    for (int i = 0; i < freq.size(); i++)
        freq[i]--;

    vi narr(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--)
        narr[freq[((arr[i] - mn) / exp) % div]] = arr[i], freq[((arr[i] - mn) / exp) % div]--;

    arr = narr;
}

void dateSort(vi &arr)
{
    int mx = *max_element(all(arr));

    int exp = 1e6, div = 100; // for days
    countSort(arr, exp, div, 32);

    exp = 1e4, div = 100; // for months
    countSort(arr, exp, div, 13);

    exp = 1, div = 10000; // for years
    countSort(arr, exp, div, 2501);
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    dateSort(arr);
    parr(arr, arr.size());
    cout << endl;
}

int main()
{
    cout << "Hello world!\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();
    return 0;
}

/*
5
12041996
20101996
05061997
12041989
11081987

*/