// 1. You are given an array(arr) of integers.
// 2. You have to sort the given array in increasing order using count sort.
// 1. You are given an array(arr) of integers.
// 2. You have to sort the given array in increasing order using count sort.

#include "../header.h"
void prefixSum(vi &arr)
{
    for (int i = 1; i < arr.size(); i++)
        arr[i] += arr[i - 1];
}

void countSort(vi &arr)
{
    int mx = *max_element(all(arr));
    int mn = *min_element(all(arr));
    int range = mx - mn + 1;
    vi freq(range);
    for (int i = 0; i < arr.size(); i++)
        freq[arr[i] - mn]++;

    prefixSum(freq);

    for (int i = 0; i < freq.size(); i++)
        freq[i]--;

    vi narr(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--)
        narr[freq[arr[i] - mn]] = arr[i], freq[arr[i] - mn]--;

    arr = narr;
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    countSort(arr);
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
7 -2 4 1 3

6
1 2 3 4 5 6

*/
