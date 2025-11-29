#include "../header.h"
int main()
{
    string str;
    cin >> str;
    int n = str.length();
    int dp[N][N];
    fill(*dp, *dp + n * n, 0);

    //-----------------------------------------------------

    for (int g = 0; g < n; g++)
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
                dp[i][j] = 0;
            else if (g == 1)
            {
                char ch1 = str[i];
                char ch2 = str[j];
                if (ch1 != ch2)
                    dp[i][j] = 1;
            }
            else
            {
                char ch1 = str[i];
                char ch2 = str[j];

                if (ch1 == ch2)
                    dp[i][j] = dp[i + 1][j - 1];

                else
                {
                    int val = INT_MAX;
                    for (int k = 0; k < j; k++)
                        val = min(val, 1 + dp[i][k] + dp[k + 1][j]);
                    dp[i][j] = val;
                }
            }
        }

    //-----------------------------------------------------

    cout << "\nHello world!\n";
    pmatrix(dp, n, n);
    return 0;
}

// =============== Optimised Approach ===============
// Precompute palindrome table
void computePalTable(const string &s, vector<vector<bool>> &pal) {
    int n = s.size();
    for (int g = 0; g < n; g++) {
        for (int i = 0, j = g; j < n; i++, j++) {
            if (g == 0) {
                pal[i][j] = true;
            } else if (g == 1) {
                pal[i][j] = (s[i] == s[j]);
            } else {
                pal[i][j] = (s[i] == s[j] && pal[i+1][j-1]);
            }
        }
    }
}

// Function to compute min cuts
int minPalindromeCuts(const string &s) {
    int n = s.size();
    vector<int> dp(n, 0);
    vector<vector<bool>> pal(n, vector<bool>(n, false));

    // Precompute palindromes in O(n^2)
    computePalTable(s, pal);

    // Fill DP
    for (int i = 0; i < n; i++) {
        if (pal[0][i]) {
            dp[i] = 0; // no cut needed if whole substring is palindrome
        } else {
            int best = INT_MAX;
            for (int j = 0; j < i; j++) {
                if (pal[j+1][i]) {
                    best = min(best, dp[j] + 1);
                }
            }
            dp[i] = best;
        }
    }
    return dp[n-1];
}


// abccbc
