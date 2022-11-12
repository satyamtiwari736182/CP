// 1. You are given a string str.
// 2. You are required to print the length of longest of palindromic substrings in string str.

#include "../header.h"

int main()
{
    string str;
    cin >> str;
    int n = str.length(), dp[20][20];
    memset(dp, 0, sizeof(dp));
    for (int g = 0; g < n; g++)
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
                dp[i][j] = 1;
            else if (g == 1)
            {
                if (str[i] == str[j])
                    dp[i][j] = 2;
                else
                    dp[i][j] = 0;
            }
            else
            {
                if (str[i] == str[j])
                    dp[i][j] = dp[i + 1][j - 1] ? 2 + dp[i + 1][j - 1] : 0;
                else
                    dp[i][j] = 0;
            }
        }

    pmatrix(dp, n, n);
    return 0;
}
// abccbc
