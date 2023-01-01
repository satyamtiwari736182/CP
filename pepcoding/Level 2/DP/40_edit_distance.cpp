/*
1. You are given two strings s1 and s2.
2. You have to find the minimum number of operations needed to convert s1 to s2.
   Operations allowed are -
   Insert - You can insert any character in s1.
   Remove - You can remove any character in s1.
   Replace - You can replace any character in s1 with any other character.
*/

#include "../header.h"

int sol(string str1, string str2, int i, int j)
{

    if (i == 0)
        return j;
    if (j == 0)
        return i;

    if (str1[i - 1] == str2[j - 1])
        return sol(str1, str2, i - 1, j - 1);

    return 1 + min(sol(str1, str2, i, j - 1),
                   min(sol(str1, str2, i - 1, j),
                       sol(str1, str2, i - 1, j - 1)));
}
int main()
{
    string str1, str2; // convert str1 -> str2
    cin >> str1 >> str2;
    str1 = " " + str1;
    str2 = " " + str2;
    int n1 = str1.length();
    int n2 = str2.length();

    cout << sol(str1, str2, n1, n2) << endl;

    int dp[N][N];
    fill(*dp, *dp + n1 * n2, 0);
    //-----------------------------------------------------

    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 0;
            else if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else
            {
                if (str1[i] == str2[j])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}); // insert,remove,replace
            }
        }

    //-----------------------------------------------------

    cout << "\nHello world!\n";
    pmatrix(dp, n1, n2);
    return 0;
}

// abcd
// aebd
