#include "../header.h"

int main()
{
    string str1, str2; // convert str1 -> str2
    cin >> str1 >> str2;
    str1 = " " + str1;
    str2 = " " + str2;
    int n1 = str1.length();
    int n2 = str2.length();

    int dp[N][N];
    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), 0);

    //-----------------------------------------------------
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 0;
            else if (i == 0)
                dp[i][j] = str2[j] + dp[i][j - 1];
            else if (j == 0)
                dp[i][j] = str1[i] + dp[i - 1][j];
            else if (str1[i] == str2[j])
                dp[i][j] += dp[i - 1][j - 1];
            else
                dp[i][j] += min(str1[i] + dp[i - 1][j], str2[j] + dp[i][j - 1]);
        }
    //-----------------------------------------------------
    cout << "cost: " << dp[n1 - 1][n2 - 1];
    cout << "\nHello world!\n";

    pmatrix(dp, n1, n2);
    return 0;
}

// pepcoder
// peerdcop
