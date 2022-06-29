// 1. You are given two sorted arrays(a,b) of integers.
// 2. You have to merge them and form one sorted array.
// 3. You have to do it in linear time complexity.

#include "../header.h"

vi merge(vi &arr1, vi &arr2)
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

void solve()
{
    int n;
    cin >> n;
    vi arr1(n);
    rarr(arr1, 0, n);

    cin >> n;
    vi arr2(n);
    rarr(arr2, 0, arr2.size());

    vi arr = merge(arr1, arr2);
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
-2 1 3 4 7

6
1 2 3 4 5 6

*/
