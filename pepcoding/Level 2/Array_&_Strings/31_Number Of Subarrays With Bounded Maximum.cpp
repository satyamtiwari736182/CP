// 1. We have an array 'arr' of positive integers, and two positive integers left and right (left is smaller than right).
// 2. Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least left and at most right.

#include "../header.h"

void solve()
{
    int n, left, right;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cin >> left >> right;
    int si = 0, ei = 0, ans = 0, prev_cnt = 0;

    while (ei < n)
    {
        if (left <= arr[ei] && arr[ei] <= right)
            prev_cnt = ei - si + 1, ans += prev_cnt;
        else if (arr[ei] < left)
            ans += prev_cnt;
        else
            si = ei + 1;
        ei++;
    }

    cout << ans << endl;
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
2 1 4 3
2
3
*/
