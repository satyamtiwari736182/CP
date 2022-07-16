// 1. You are given a number n, representing the number of houses.
// 2. In the next n rows, you are given 3 space separated numbers representing the cost of painting nth house with red or blue or green color.
// 3. You are required to calculate and print the minimum cost of painting all houses without painting any consecutive house with same color.

#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    vvi arr(n, vi(3)), dp(n, vi(3));
    rmatrix(arr, n, 3);
    cout << "\n********\n";
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    for (int house = 1; house < n; house++)
    {
        dp[house][0] = arr[house][0] + min(dp[house - 1][1], dp[house - 1][2]);
        dp[house][1] = arr[house][1] + min(dp[house - 1][0], dp[house - 1][2]);
        dp[house][2] = arr[house][2] + min(dp[house - 1][0], dp[house - 1][1]);
    }

    int minCost = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));

    // pmatrix(dp, n, 3);

    cout << endl;
    cout << minCost;
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
4
1 5 7
5 8 4
3 2 9
1 2 4
*/