// 1. You are given an array(arr) of integers.
// 2. You have to sort the given array in increasing order using the merge sort.

#include "../header.h"

vi merge(vi arr1, vi arr2)
{
    vi arr(arr1.size() + arr2.size());
    int i = 0, j = 0, idx = 0;
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
            arr[idx] = arr1[i], i++, idx++;
        else
            arr[idx] = arr2[j], j++, idx++;
    }

    while (i < arr1.size())
        arr[idx] = arr1[i], i++, idx++;

    while (j < arr2.size())
        arr[idx] = arr2[j], j++, idx++;

    return arr;
}

vi mergeSort(vi &arr, int left, int right)
{
    if (left == right)
        return {arr[left]};
    int mid = (left + right) / 2;
    vi arr1 = mergeSort(arr, left, mid);
    vi arr2 = mergeSort(arr, mid + 1, right);
    return merge(arr1, arr2);
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);

    vi arr1 = mergeSort(arr, 0, n - 1);
    parr(arr1, arr1.size());
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
5 4 6 2 1 3

*/
