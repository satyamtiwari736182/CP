// 1. You are given a number n and a number k in separate lines, representing the number of fences and number of colors.
// 2. You are required to calculate and print the number of ways in which the fences could be painted so that not more than two consecutive  fences have same colors.

#include "../header.h"

void solve()
{
    int n, c;
    cin >> n >> c;
    vvi dp(3, vi(n));
    int bothSame = 0, bothDiff = 1, totalCnt = 2;
    dp[bothSame][1] = c;
    dp[bothDiff][1] = c * (c - 1);
    dp[totalCnt][1] = dp[bothSame][1] + dp[bothDiff][1];

    for (int house = 2; house < n; house++)
    {
        dp[bothSame][house] = dp[bothDiff][house - 1] * 1;
        dp[bothDiff][house] = dp[totalCnt][house - 1] * (c - 1);
        dp[totalCnt][house] = dp[bothSame][house] + dp[bothDiff][house];
    }
    cout << endl;

    pmatrix(dp, 3, n);

    int ans = dp[2][n - 1];
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
5 3
*/
