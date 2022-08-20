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
    for (int i = n1-1; i >= 0; i--)
        for (int j = n2-1; j >= 0; j--)
        {
            if (i == n1-1 || j == n2-1)
                dp[i][j] = 0;
            else
            {
                char ch1 = str1[i];
                char ch2 = str2[j];
                if (ch1 == ch2)
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    //-----------------------------------------------------

    cout << "\nHello world!\n";
    pmatrix(dp, n1, n2);
    return 0;
}

// abcd
// aebd
