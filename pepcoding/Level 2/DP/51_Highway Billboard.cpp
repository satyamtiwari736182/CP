// 1. You are given a number M representing length of highway(range).
// 2. You are given a number N representing number of bill boards.
// 3. You are given N space separated numbers representing (P)position of bill-boards.
// 4. You are given N space separated numbers representing (R)revenue corresponding to each (P)position.
// 5. You are given a number T such that bill-boards can only be placed after specific distance(T).
// 6. Find the maximum revenue that can be generated.

#include "../header.h"

int solution(int m, vi &x, vi &rev, int t)
{
    int dp[N]; // x.size();
    int ans = 0;
    dp[0] = rev[0];
    for (int i = 1; i < x.size(); i++)
    {
        int maxVal = 0;
        for (int j = 0; j < i; j++)
        {
            int dist = x[i] - x[j];
            if (dist > t)
                maxVal = max(maxVal, dp[j]);
        }
        dp[i] = maxVal + rev[i];
        ans = max(ans, dp[i]);
    }
    return ans;
}

int solution_II(int m, vi &x, vi &rev, int t)
{
    unordered_map<int, int> hashmap;
    for (int i = 0; i < x.size(); i++)
        hashmap[x[i]] = rev[i];
    int dp[N]; // size => m+1
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        if (hashmap.count(i) == false)
            dp[i] = dp[i - 1];
        else
        {
            int boardNotInstalled = dp[i - 1];
            int boardInstalled = hashmap[i];
            if (i >= t + 1)
                boardInstalled += dp[i - t - 1];
            dp[i] = max(boardNotInstalled, boardInstalled);
        }
    }
    return dp[m];
}

int main()
{
    cout << "\nHello world!\n";
    int m, n, t;

    cin >> m >> n;
    vi x(n), rev(n);
    rarr(x, 0, n);
    rarr(rev, 0, n);
    cin >> t;
    cout << "\n==========\n";
    //------------------------------------------------------
    cout << solution(m, x, rev, t) << endl;
    cout << solution_II(m, x, rev, t) << endl;
    return 0;
}

/*
20
5
6 7 12 14 15
5 8 5 3 1
5
*/
