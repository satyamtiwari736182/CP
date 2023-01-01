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
                dp[i][j] = 1;
            else
            {
                if (str[i] == str[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    //-----------------------------------------------------

    cout << "\nHello world!\n";
    pmatrix(dp, n, n);
    return 0;
}

// abkccbc

/*
    string str1="",str2="";

    int dp[1001][1001];

    int solve(int i,int j){
        if(i==str1.length() || j==str1.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(str1[i]==str2[j]) return dp[i][j]=1+solve(i+1,j+1);
        return dp[i][j]=max(solve(i+1,j),solve(i,j+1));
    }

    int longestPalindromeSubseq(string s) {
        str1=s;
        reverse(begin(s),end(s));
        str2=s;
        memset(dp,-1,sizeof(dp));
        return solve(0,0);
    }
*/