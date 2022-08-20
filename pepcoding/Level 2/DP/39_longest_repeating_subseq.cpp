#include "../header.h"
int main()
{
    string str;
    cin >> str;
    int n = str.length() + 1;

    int dp[N][N];
    fill(*dp, *dp + n * n, 0);

    //-----------------------------------------------------
    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == n - 1 || j == n - 1)
                dp[i][j] = 0;
            else
            {
                char ch1 = str[i];
                char ch2 = str[j];
                if (ch1 == ch2 && i != j)
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    //-----------------------------------------------------

    cout << "\nHello world!\n";
    pmatrix(dp, n, n);
    return 0;
}

// abacbc
