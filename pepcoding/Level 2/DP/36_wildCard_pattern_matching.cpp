/*
1. You are given two strings S1 and S2. S1 represents a text and S2 represents a wildcard pattern.
2. You have to print 'true' if the wildcard pattern is matched with the given text, otherwise print 'false'.

The wildcard pattern can include the characters '?' and '*'
'?' - matches any single character
'*' - matches any sequence of characters (including the empty sequence)

*/

#include "../header.h"

int main()
{
    string str, pattern;
    cin >> str >> pattern;
    int m = str.length() + 1;
    int n = pattern.length() + 1;
    bool dp[N][M];
    fill(*dp, *dp + n * m, 0);

    //-----------------------------------------------------
    dp[n - 1][m - 1] = true;
    for (int i = n - 2; i >= 0; i--)
        for (int j = m - 2; j >= 0; j--)
        {
            if (pattern[i] == str[j])
                dp[i][j] = dp[i + 1][j + 1];
            else
            {
                if (pattern[i] == '?')
                    dp[i][j] = dp[i + 1][j + 1];
                else if (pattern[i] == '*')
                    for (int k = j; k < m - 1; k++)
                        dp[i][j] = max(dp[i][j], dp[i + 1][k + 1]);
                else
                    dp[i][j] = false;
            }
        }
    //-----------------------------------------------------

    cout << "\nHello world!\n";
    pmatrix(dp, n, m);
    return 0;
}

// abcbac
