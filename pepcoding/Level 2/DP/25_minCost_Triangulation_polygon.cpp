#include "../header.h"

int main()
{
    int n;
    cin >> n;

    int arr[N], dp[N][N];
    fill(*dp, *dp + n * n, 0);
    rarr(arr, 0, n);

    //-----------------------------------------------------
    for (int g = 0; g < n; g++)
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0 || g == 1)
                dp[i][j] = 0;
            else if (g == 2)
                dp[i][j] = arr[i] * arr[i + 1] * arr[j];
            else
            {
                int minCost = INT_MAX;
                for (int k = i + 1; k < j; k++)
                    minCost = min(minCost, arr[i] * arr[k] * arr[j] + dp[i][k] + dp[k][j]);
                dp[i][j] = minCost;
            }
        }

    //-----------------------------------------------------

    cout << "\nHello world!\n"
         << dp[0][n - 1] << endl;
    pmatrix(dp, n, n);
    return 0;
}

// 6
// 2 3 1 5 6 4
