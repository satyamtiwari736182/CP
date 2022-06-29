// 1. You are given an array(arr) of integers.
// 2. You have to sort the given array in increasing order using radix sort.


#include "../header.h"
void prefixSum(vi &arr)
{
    for (int i = 1; i < arr.size(); i++)
        arr[i] += arr[i - 1];
}

void countSort(vi &arr, int exp)
{
    int mx = 9;
    int mn = 0;
    int range = mx - mn + 1;
    vi freq(range);
    for (int i = 0; i < arr.size(); i++)
        freq[((arr[i] - mn) / exp) % 10]++;

    prefixSum(freq);

    for (int i = 0; i < freq.size(); i++)
        freq[i]--;

    vi narr(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--)
        narr[freq[((arr[i] - mn) / exp) % 10]] = arr[i], freq[((arr[i] - mn) / exp) % 10]--;

    arr = narr;
}

void radixSort(vi &arr)
{
    int mx = *max_element(all(arr));
    for (int exp = 1; exp <= mx; exp *= 10)
        countSort(arr, exp);
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    radixSort(arr);
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
7 2 4 1 3

6
1 2 3 4 5 6

*/
