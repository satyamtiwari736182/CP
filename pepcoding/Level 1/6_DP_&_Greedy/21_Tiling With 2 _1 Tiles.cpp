// 1. You are given a number n representing the length of a floor space which is 2m wide. It's a 2 * n board.
// 2. You've an infinite supply of 2 * 1 tiles.
// 3. You are required to calculate and print the number of ways floor can be tiled using tiles.

#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    vi dp(n + 1);
    dp[1] = 1, dp[2] = 2;

    for (int floor = 3; floor <= n; floor++)
        dp[floor] = dp[floor - 1] + dp[floor - 2];

    cout << dp[n] << endl;
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
// 8