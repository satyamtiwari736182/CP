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
                dp[i][j] = 1;
            else
            {
                if (str[i] == str[j])
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1;
                else
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1]; // f(c1M)+f(Mc2)-f(M)
            }
        }
    //-----------------------------------------------------

    cout << "\nHello world!\n";
    pmatrix(dp, n, n);
    return 0;
}

// abkccbc
