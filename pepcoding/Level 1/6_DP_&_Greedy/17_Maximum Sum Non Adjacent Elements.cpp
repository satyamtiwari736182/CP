// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers, representing n elements.
// 3. You are required to find the maximum sum of a subsequence with no adjacent elements.

#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    int include = arr[0], exclude = 0;
    for (int i = 1; i < n; i++)
    {
        int new_inc = exclude + arr[i];
        int new_exc = max(include, exclude);
        include = new_inc;
        exclude = new_exc;
    }
    int ans = max(include, exclude);
    cout << ans << endl;
}

int main()
{
    cout << "Hello world!\n";
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

/*
6
5
10
10
100
5
6
*/

// 6
// 5
// 10
// 10
// 100
// 5
// 6