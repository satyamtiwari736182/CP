// 1. Given an integer array 'arr'.
// 2. Reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
// 3. You may assume the input array always has a valid answer.
// Note : You can return answer in any order.


#include "../header.h"

void solve()
{
    int arr[100], res[100], n;
    cin >> n;
    rarr(arr, 0, n);

    // 1. Sort array
    sort(arr, arr + n);

    // 2. make an extra array and manage equility condition.
    int i = 1, j = n - 1;
    while (i < n)
        res[i] = arr[j], i += 2, j--;

    i = 0;
    while (i < n)
        res[i] = arr[j], i += 2, j--;

    // 3.copy required array in original list.
    for (int i = 0; i < n; i++)
        arr[i] = res[i];

    parr(arr, n);
}

int main()
{
    cout << "\nHello world\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();

    return 0;
}

/*

6
1 5 1 1 6 4

*/
