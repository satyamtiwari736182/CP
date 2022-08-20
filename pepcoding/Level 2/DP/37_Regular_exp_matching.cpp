#include "../header.h"

int main()
{
    string str, pattern;
    cin >> str >> pattern;
    str = " " + str;
    pattern = " " + pattern;
    int n1 = str.length();
    int n2 = pattern.length();
    bool dp[N][N];
    fill(*dp, *dp + n1 * n2, 0);

    //-----------------------------------------------------
    for (int i = 0; i < n2; i++)
        for (int j = 0; j < n1; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else if (j == 0)
            {
                if (pattern[i] == '*')
                    dp[i][j] = dp[i - 2][j];
                else
                    dp[i][j] = false;
            }
            else
            {
                if (pattern[i] == '*')
                {
                    dp[i][j] = dp[i - 2][j];
                    if (pattern[i - 1] == str[j] || pattern[i - 1] == '.')
                        dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
                else if (pattern[i] == str[j] || pattern[i] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = false;
            }
        }

    //-----------------------------------------------------

    cout << "\nHello world!\n";
    pmatrix(dp, n2, n1);
    return 0;
}

// abcbac
