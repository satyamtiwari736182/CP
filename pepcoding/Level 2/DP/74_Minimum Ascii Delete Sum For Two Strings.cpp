// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

#include "../header.h"
int getSum(string str, int idx)
{
    int sum = 0;
    for (int i = 0; i < idx; i++)
        sum += str[i];
    return sum;
}
int rec(string str1, string str2, int n, int m)
{
    if (m == 0)
    {
        int charSum = getSum(str1, n);
        return charSum;
    }
    if (n == 0)
        return getSum(str2, m);

    if (str1[n - 1] == str2[m - 1])
        return rec(str1, str2, n - 1, m - 1);
    else
    {
        int ans1 = str1[n - 1] + rec(str1, str2, n - 1, m);
        int ans2 = str2[m - 1] + rec(str1, str2, n, m - 1);
        return min(ans1, ans2);
    }
}

int dp[N][N];
int tab(string str1, string str2, int N, int M)
{
    for (int n = 0; n <= N; n++)
    {
        for (int m = 0; m <= M; m++)
        {
            if (m == 0)
            {
                int charSum = getSum(str1, n);
                dp[n][m] = charSum; // return charSum;
            }
            else if (n == 0)
                dp[n][m] = getSum(str2, m); // return getSum(str2, m);

            else if (str1[n - 1] == str2[m - 1])
                dp[n][m] = dp[n - 1][m - 1]; // return rec(str1, str2, n - 1, m - 1);
            else
            {
                int ans1 = str1[n - 1] + dp[n - 1][m]; // rec(str1, str2, n - 1, m);
                int ans2 = str2[m - 1] + dp[n][m - 1]; // rec(str1, str2, n, m - 1);
                dp[n][m] = min(ans1, ans2);            // return min(ans1, ans2);
            }
        }
    }
    // cout << N << M << endl;
    return dp[N][M];
}

int main()
{
    cout << "\nHello world!\n";
    string str1, str2;
    cin >> str1 >> str2;
    cout << "\n------------\n";
    cout << rec(str1, str2, str1.length(), str2.length()) << endl;
    memset(dp, 0, sizeof(dp));
    cout << tab(str1, str2, str1.length(), str2.length()) << endl;
    //------------------------------------------------------
    cout << endl;
    return 0;
}

/*
sea
eat
-------
*/
