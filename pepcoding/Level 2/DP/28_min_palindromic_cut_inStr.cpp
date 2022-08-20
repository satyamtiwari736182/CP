#include "../header.h"
int main()
{
    string str;
    cin >> str;
    int n = str.length();
    int dp[N][N];
    fill(*dp, *dp + n * n, 0);

    //-----------------------------------------------------

    for (int g = 0; g < n; g++)
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
                dp[i][j] = 0;
            else if (g == 1)
            {
                char ch1 = str[i];
                char ch2 = str[j];
                if (ch1 != ch2)
                    dp[i][j] = 1;
            }
            else
            {
                char ch1 = str[i];
                char ch2 = str[j];

                if (ch1 == ch2)
                    dp[i][j] = dp[i + 1][j - 1];

                else
                {
                    int val = INT_MAX;
                    for (int k = 0; k < j; k++)
                        val = min(val, 1 + dp[i][k] + dp[k + 1][j]);
                    dp[i][j] = val;
                }
            }
        }

    //-----------------------------------------------------

    cout << "\nHello world!\n";
    pmatrix(dp, n, n);
    return 0;
}

// 8
// 1 5 8 9 10 17 17 20
