// 1. Given an integer array nums.
// 2. Partition it into two (contiguous) subarrays left and right so that:
//     a. Every element in left is less than or equal to every element in right.
//     b. Left and right are non-empty.
//     c. Left has the smallest possible size.
// 3. Return the length of left after such a partitioning.
// NOTE : Test cases are generated such that partitioning exists.

#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    int leftMax = arr[0], greater = arr[0], ans = 0, i = 0;

    while (i < n)
    {
        if (arr[i] < leftMax)
            ans = i, leftMax = greater;
        else
            greater = arr[i];
        i++;
    }

    cout << ans + 1 << endl;
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
11
7 3 9 5 10 1 15 16 19 14 30

5
5 0 3 8 6

*/


