#include "../header.h"

int main()
{
    int n;
    cin >> n;

    int arr[n + 1], dp[n][n];
    fill(*dp, *dp + n * n, 0);
    rarr(arr, 0, n + 1);

    //-----------------------------------------------------
    for (int g = 0; g < n; g++)
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
                dp[i][j] = 0;
            else if (g == 1)
                dp[i][j] = arr[i] * arr[j] * arr[j + 1];
            else
            {
                int prod = 0;
                for (int k = i; k < j; k++)
                {
                    int lm = dp[i][k];
                    int rm = dp[k + 1][j];
                    int mul = arr[i] * arr[k + 1] * arr[j + 1];
                    prod = max(prod, lm + rm + mul);
                }
                dp[i][j] = prod;
            }
        }
    //-----------------------------------------------------

    cout << "\nHello world!\n";
    pmatrix(dp, n, n);
    return 0;
}

// 5
// 10 20 30 40 50 60
