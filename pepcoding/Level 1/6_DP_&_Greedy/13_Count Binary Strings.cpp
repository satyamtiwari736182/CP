// 1. You are given a number n.
// 2. You are required to print the number of binary strings of length n with no consecutive 0's.
#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    vvi dp(2, vi(n + 1));

    dp[0][1] = dp[1][1] = 1;

    for (int i = 2; i <= n; i++)
        dp[0][i] = dp[1][i - 1], dp[1][i] = dp[0][i - 1] + dp[1][i - 1];
    pmatrix(dp, 2, n + 1);

    int cnt = dp[0][n] + dp[1][n];
    cout << cnt;
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

// 6