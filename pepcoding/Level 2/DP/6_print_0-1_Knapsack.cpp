#include "../header.h"

int main()
{
    int n, cap;
    cin >> n;
    int wt[n + 1] = {0}, prof[n + 1] = {0};
    rarr(prof, 1, n + 1);
    rarr(wt, 1, n + 1);
    cin >> cap;
    int dp[n + 1][cap + 1];

    fill(*dp, *dp + (n + 1) * (cap + 1), 0);

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= cap; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (wt[i] > j)
                dp[i][j] = dp[i - 1][j];

            else
                dp[i][j] = max(dp[i - 1][j], prof[i] + dp[i - 1][j - wt[i]]);
        }

    cout << "\n***********************\n"
         << dp[n][cap]
         << endl;
    pmatrix(dp, n + 1, cap + 1);

    return 0;
}

// 5
// 15 14 10 45 30
// 2 5 1 3 4
// 7
