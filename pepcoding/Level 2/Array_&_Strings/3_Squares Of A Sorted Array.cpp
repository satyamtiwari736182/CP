// 1. Given an integer array 'nums' sorted in non-decreasing order.
// 2. Return an array of the squares of each number sorted in non-decreasing order.

#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    vi arr(n), ans(n);
    rarr(arr, 0, n);

    int i = 0, j = n - 1, idx = 0;
    while (i < j)
    {
        int isqr = arr[i] * arr[i], jsqr = arr[j] * arr[j];
        if (isqr > jsqr)
            ans[idx] = isqr, i++;
        else
            ans[idx] = jsqr, j--;
        idx++;
    }
    parr(ans, n);
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
9
-6 -2 -1 0 1 4 5 7 9
*/
