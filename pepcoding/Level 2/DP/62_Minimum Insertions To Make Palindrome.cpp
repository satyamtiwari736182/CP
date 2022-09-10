// 1. You are given a string(str).
// 2. You have to find the minimum number of characters to be inserted to convert it to a palindrome

#include "../header.h"

int solution(string str)
{
    int dp[N][N];
    fill(&dp[0][0], &dp[N - 1][N - 1] + 1, 0);
    for (int gap = 0; gap < str.length(); gap++)
        for (int si = 0, ei = gap; ei < str.length(); si++, ei++)
        {
            if (gap == 0)
                dp[si][ei] = 1;
            else
            {
                if (str[si] == str[ei])
                    dp[si][ei] = dp[si + 1][ei - 1] + 2;
                else
                    dp[si][ei] = max(dp[si + 1][ei], dp[si][ei - 1]);
            }
        }

    int ans = str.length() - dp[0][str.length() - 1];
    return ans;
}

int main()
{
    cout << "\nHello world!\n";
    string str;
    cin >> str;

    cout << "\n------------\n";
    cout << solution(str) << endl;

    //------------------------------------------------------

    return 0;
}

/*
pepperatcoding
*/
