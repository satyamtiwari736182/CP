// 1. You are given a number n and a number m separated by line-break representing the length and breadth of a m * n floor.
// 2. You've an infinite supply of m * 1 tiles.
// 3. You are required to calculate and print the number of ways floor can be tiled using tiles.

#include "../header.h"

void solve()
{
    int n, m;
    cin >> n >> m;
    vi dp(n + 1);

    for (int floor = 1; floor <= n; floor++)
    {
        if (floor < m)
            dp[floor] = floor; // for rhs  floor=> count of tiles;
        else if (floor == m)
            dp[floor] = 2;
        else
            dp[floor] = dp[floor - 1] + dp[floor - m];
    }

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
// 39
// 16
