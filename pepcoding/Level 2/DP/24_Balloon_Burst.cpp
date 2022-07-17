#include "../header.h"

int main()
{
    int n;
    cin >> n;

    int arr[n], dp[n][n];
    fill(*dp, *dp + n * n, 0);
    rarr(arr, 0, n);

    //-----------------------------------------------------
    for (int g = 0; g < n; g++)
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
                dp[i][j] = (i == 0 ? 1 : arr[i - 1]) * arr[i] * (j == n - 1 ? 1 : arr[j + 1]);
            else
            {
                int maxCoin = 0;
                for (int k = i; k <= j; k++)
                {
                    int left = k == 0 ? 0 : dp[i][k - 1];
                    int burstK = (i == 0 ? 1 : arr[i - 1]) * arr[k] * (j == n - 1 ? 1 : arr[j + 1]);
                    int right = k == n - 1 ? 0 : dp[k + 1][j];
                    maxCoin = max(maxCoin, left + burstK + right);
                }
                dp[i][j] = maxCoin;
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
