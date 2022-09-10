// 1. You are given two strings S1 and S2.
// 2. You have to find the number of unique ways in which you can transform S1 to S2.
// 3. Transformation can be achieved by removing 0 or more characters from S1, such that the sequence formed by the remaining characters of S1 is identical to S2.

#include "../header.h"

int solution(string str, string tar, int si, int ti)
{
    if (si == str.length())
    {
        if (ti < tar.length())
            return 0;
        else
            return 1;
    }

    else if (ti == tar.length())
        return 1;

    char c1 = str[si], c2 = tar[ti];
    int tarWord = 0;

    if (c1 != c2)
        tarWord = solution(str, tar, si + 1, ti);

    else
    {
        int tw1 = solution(str, tar, si + 1, ti);
        int tw2 = solution(str, tar, si + 1, ti + 1);
        tarWord = tw1 + tw2;
    }

    return tarWord;
}

int solution_tab(string str, string tar)
{
    vvi dp(tar.size(), vi(str.size()));
    for (int i = dp.size() - 1; i >= 0; i--)
        for (int j = dp[0].size() - 1; j >= 0; j--)
        {
            if (i == dp.size() - 1)
                dp[i][j] = 1;

            else if (j == dp[0].size() - 1)
                dp[i][j] = 0;

            else
            {
                char c1 = tar[i], c2 = str[j];
                if (c1 != c2)
                    dp[i][j] = dp[i][j + 1];
                else
                    dp[i][j] = dp[i][j + 1] + dp[i + 1][j + 1];
            }
        }
    return dp[0][0];
}

int main()
{
    cout << "\nHello world!\n";
    string str, tar;
    cin >> str >> tar;
    cout << "\n==========\n";
    //------------------------------------------------------
    cout << solution(str, tar, 0, 0) << endl;
    cout << solution_tab(str, tar) << endl;
    return 0;
}

/*
abcccdf
abccdf

************
aaaabbbccd
abcd
*/
