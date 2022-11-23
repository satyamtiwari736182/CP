/*
1. You are given two strings S1, S2, and two numbers x and y.
2. The cost of deleting a character from S1 is x and the cost of deleting a character from S2 is y.
3. You can delete characters from both the strings.
4. You have to find the minimum cost required to make the given two strings identical.
*/

#include "../header.h"

int main()
{
    string str1, str2; // convert str1 -> str2
    int x, y;
    cin >> str1 >> str2;
    cin >> x >> y;
    str1 = " " + str1;
    str2 = " " + str2;
    int n1 = str1.length();
    int n2 = str2.length();

    int dp[N][N];
    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), 0);

    //-----------------------------------------------------

    // Similar to ASCII cost character deletion program
    /*for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 0;
            else if (i == 0)
                dp[i][j] = y + dp[i][j - 1];
            else if (j == 0)
                dp[i][j] = x + dp[i - 1][j];
            else if (str1[i] == str2[j])
                dp[i][j] += dp[i - 1][j - 1];
            else
                dp[i][j] += min(x + dp[i - 1][j], y + dp[i][j - 1]);
        }*/

    //-----------------------------------------------------

    // Using LCS concept as deletion cost is constant from either of the string
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 0;
            else if (i == 0)
                dp[i][j] = 0;
            else if (j == 0)
                dp[i][j] = 0;
            else if (str1[i] == str2[j])
                dp[i][j] += 1 + dp[i - 1][j - 1];
            else
                dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
        }

    //-----------------------------------------------------
    int lcs = dp[n1 - 1][n2 - 1];
    cout << "cost: " << (x * (n1 - 1 - lcs) + y * (n2 - 1 - lcs));
    cout << "\nHello world!\n";

    pmatrix(dp, n1, n2);
    return 0;
}

// pepcoder
// peerdcop
