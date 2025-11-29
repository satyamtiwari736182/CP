// 1. You are given a number n, which represents the length of a road. The road has n plots on it's each side.
// 2. The road is to be so planned that there should not be consecutive buildings on either side of the road.
// 3. You are required to find and print the number of ways in which the buildings can be built on both side of roads.

#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    vvi dp(2, vi(n + 1));

    dp[0][1] = dp[1][1] = 1;

    for (int i = 2; i <= n; i++)
        dp[0][i] = dp[1][i - 1], 
        dp[1][i] = dp[0][i - 1] + dp[1][i - 1];
    pmatrix(dp, 2, n + 1);

    int cnt = dp[0][n] + dp[1][n];
    cout << cnt * cnt;
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
*/