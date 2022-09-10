// 1. You are given three strings - s1, s2 and s3.
// 2. You have to find whether s3 is formed by interleaving of s1 and s2.
// 3. s3 is interleaving if it contains all characters of s1 and s2, and order of all characters in individual string is preserved.


#include "../header.h"

bool solution_I(string str1, string str2, string str3, int i, int j)
{
    if (i == str1.length() && j == str2.length())
        return true;

    if (i < str1.length() && str1[i] == str3[i + j])
    {
        bool f1 = solution_I(str1, str2, str3, i + 1, j);
        if (f1 == true)
            return true;
    }

    if (i < str2.length() && str2[j] == str3[i + j])
    {
        bool f2 = solution_I(str1, str2, str3, i, j + 1);
        if (f2 == true)
            return true;
    }

    return false;
}

bool solution_II(string str1, string str2, string str3)
{
    vvi dp(str1.length() + 1, vi(str2.length() + 1));
    for (int i = 0; i < str1.length() + 1; i++)
    {
        for (int j = 0; j < str2.length() + 1; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true;

            else if (i == 0)
                dp[i][j] = str2[j - 1] == str3[i + j - 1] ? dp[i][j - 1] : false;

            else if (j == 0)
                dp[i][j] = str1[i - 1] == str3[i + j - 1] ? dp[i - 1][j] : false;

            else
            {
                if (str1[i - 1] == str3[i + j - 1])
                    dp[i][j] = dp[i - 1][j];

                if (!dp[i][j] && str2[j - 1] == str3[i + j - 1])
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }

    return dp[str1.length()][str2.length()];
}

int main()
{
    cout << "\nHello world!\n";
    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;

    cout << "\n------------\n";
    cout << solution_I(str1, str2, str3, 0, 0) << endl;
    cout << solution_II(str1, str2, str3) << endl;
    //------------------------------------------------------

    return 0;
}

/*
aabcc
dbbca
aadbbcbcac
*/
