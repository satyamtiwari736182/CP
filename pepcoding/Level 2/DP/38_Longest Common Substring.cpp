// 1. You are given two strings S1 and S2.
// 2. You are required to print the length of the longest common substring of two strings.
// Longest Commom Substring
#include "../header.h"
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int n1 = str1.length() + 1;
    int n2 = str2.length() + 1;
    int dp[N][N];
    fill(*dp, *dp + n1 * n2, 0);

    //-----------------------------------------------------
    int ans = 0;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                char ch1 = str1[i - 1];
                char ch2 = str2[j - 1];
                if (ch1 == ch2)
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    //-----------------------------------------------------

    cout << "\nHello world!\n";
    cout << ans << endl;
    pmatrix(dp, n1, n2);
    return 0;
}

// pqabcxy
// xyzabcp
/********/

// abcdgh
// acdghr