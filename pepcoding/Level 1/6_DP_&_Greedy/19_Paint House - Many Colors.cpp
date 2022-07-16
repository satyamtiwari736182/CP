// 1. You are given a number n and a number k separated by a space, representing the number of houses and number of colors.
// 2. In the next n rows, you are given k space separated numbers representing the cost of painting nth house with one of the k colors.
// 3. You are required to calculate and print the minimum cost of painting all houses without painting any consecutive house with same color.

#include "../header.h"

int minCost(vvi &dp, int house, int exptColor)
{
    int cst = INT_MAX;
    for (int color = 0; color < dp[0].size(); color++)
        if (color != exptColor)
            cst = min(cst, dp[house][color]);
    return cst;
}

void solve()
{
    int n, c;
    cin >> n >> c;
    vvi arr(n, vi(c)), dp(n, vi(c));
    rmatrix(arr, n, c);
    cout << "\n********\n";
    for (int color = 0; color < c; color++)
        dp[0][color] = arr[0][color];

    for (int house = 1; house < n; house++)
        for (int color = 0; color < c; color++)
            dp[house][color] = arr[house][color] + minCost(dp, house - 1, color);

    int minCost = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));

    pmatrix(dp, n, 3);

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
4 3
1 5 7
5 8 4
3 2 9
1 2 4
*/
