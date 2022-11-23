/*
1. You are given two strings s1 and s2.
2. A string can be represented as a binary tree by partitioning it to two non-empty substrings recursively.
3. If you choose any non-leaf node and swap its two children, then the string formed is the scramble of the original string.
4. You have to determine if s2 is a scrambled string of s1.
*/

#include "../header.h"

bool isScramble(string str1, string str2)
// Recursive approach
{
    if (str1 == str2)
        return true;

    for (int i = 1; i < str1.length(); i++)
    {
        /*
        !Note:
            * property of substr() in c++ unlike
            ? JAVA
            string str = "satyamTiwari";
            int start = 4, end = 6;
            int len = end - start;
           * cout << str.substr(4, len) << endl;
        */
        bool direct_check = isScramble(str1.substr(0, i), str2.substr(0, i)) && isScramble(str1.substr(i), str2.substr(i));

        bool cross_chk = isScramble(str1.substr(0, i), str2.substr(str2.length() - i)) && isScramble(str1.substr(i), str2.substr(0, str2.length() - i));

        if (direct_check || cross_chk)
            return true;
    }

    return false;
}
bool isScramble2(string str1, string str2, int s1i, int s1j, int s2i, int s2j)
{
    if (str1.substr(s1i, s1j - s1i + 1) == str2.substr(s2i, s2j - s2i + 1))
        return true;

    for (int k = 0; k < s1j - s1i; k++)
    {
        bool drct_chk = isScramble2(str1, str2, s1i, s1i + k, s2i, s2i + k) && isScramble2(str1, str2, s1i + k + 1, s1j, s2i + k + 1, s2j);

        bool cros_chk = isScramble2(str1, str2, s1i, s1i + k, s2j - k, s2j) && isScramble2(str1, str2, s1i + k + 1, s1j, s2i, s2j - k - 1);

        if (drct_chk || cros_chk)
            return true;
    }

    return false;
}

bool isScramble3(string str1, string str2, int s1i, int s2i, int len, int dp[N][N][N])
// Memoization
{
    if (str1.substr(s1i, len) == str2.substr(s2i, len))
        return true;

    if (dp[len][s1i][s2i] != -1)
        return dp[len][s1i][s2i];

    for (int k = 1; k < len; k++)
    {
        bool drct_chk = isScramble3(str1, str2, s1i, s2i, k, dp) && isScramble3(str1, str2, s1i + k, s2i + k, len - k, dp);

        bool cros_chk = isScramble3(str1, str2, s1i, s2i + len - k, k, dp) && isScramble3(str1, str2, s1i + k, s2i, len - k, dp);

        if (drct_chk || cros_chk)
        {
            dp[len][s1i][s2i] = true;
            return true;
        }
    }
    dp[len][s1i][s2i] = false;
    return false;
}
int main()
{
    string str1, str2; // convert str1 -> str2
    cin >> str1 >> str2;
    int n1 = str1.length();
    int n2 = str2.length();

    // cout << isScramble(str1, str2) << endl;
    // cout << isScramble2(str1, str2, 0, n1 - 1, 0, n2 - 1) << endl;
    int dp[N][N][N];
    fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(dp[0][0][0]), -1);

    if (n1 != n2)
        cout << 0 << endl;
    else
        cout << "\nAns: " << isScramble3(str1, str2, 0, 0, n1, dp) << endl;

    //-----------------------------------------------------

    // Tabulation
    // bool dp2[n1 + 1][n1][n2];
    bool dp2[N][N][N];
    fill(&dp2[0][0][0], &dp2[0][0][0] + sizeof(dp2) / sizeof(dp2[0][0][0]), 0);

    for (int len = 0; len <= n1; len++)
        for (int i = 0; i <= n1 - len; i++)
            for (int j = 0; j <= n2 - len; j++)
            {
                if (len == 1)
                    dp2[len][i][j] = str1[i] == str2[j];
                else
                    for (int k = 1; k < len && !dp2[len][i][j]; k++)
                        dp2[len][i][j] = (dp2[k][i][j] && dp2[len - k][i + k][j + k] ||
                                          dp2[k][i][j + len - k] && dp2[len - k][i + k][j]);
            }

    //-----------------------------------------------------

    cout << "\nHello world!\n"
         << dp2[n1][0][0];
    // pmatrix(dp, n1, n2);
    return 0;
}

// pepcoder
// peerdcop
