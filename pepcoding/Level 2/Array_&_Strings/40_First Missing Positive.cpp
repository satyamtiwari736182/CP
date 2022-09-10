// 1. Given an unsorted integer array 'arr'.
// 2. Find the smallest missing positive integer.
// Note : You must implement an algorithm that runs in O(n) time and uses constant extra space.

#include "../header.h"
int findMissingPositive(vi &arr)
{
    // step 1. mark element which are out of the range and manage the presence of one
    bool one = false;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            one = true;
        if (arr[i] < 1 || arr[i] > n)
            arr[i] = 1;
    }

    if (one == false)
        return 1;

    // step 2. Map element with index as if they were in sorted array
    for (int i = 0; i < n; i++)
    {
        int idx = abs(arr[i]) - 1;
        arr[idx] = -abs(arr[idx]);
    }

    // step 3. find out missing integers
    for (int i = 0; i < n; i++)
        if (arr[i] > 0)
            return i + 1;

    return n + 1;
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cout << "--------------------" << endl;
    cout << findMissingPositive(arr);
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
4
3 4 -1 1
*/
