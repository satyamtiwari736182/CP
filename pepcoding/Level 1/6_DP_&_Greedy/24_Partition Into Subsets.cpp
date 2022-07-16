// 1. You are given a number n, representing the number of elements.
// 2. You are given a number k, representing the number of subsets.
// 3. You are required to print the number of ways in which these elements can be partitioned in k non-empty subsets.
// E.g.
// For n = 4 and k = 3 total ways is 6
// 12-3-4
// 1-23-4
// 13-2-4
// 14-2-3
// 1-24-3
// 1-2-34

#include "../header.h"

void solve()
{
    int n, k;
    cin >> n >> k;
    vvi dp(k + 1, vi(n + 1));

    for (int team_cnt = 0; team_cnt <= k; team_cnt++)
        for (int person_cnt = 0; person_cnt <= n; person_cnt++)
        {
            if (team_cnt == 0 || person_cnt == 0)
                dp[team_cnt][person_cnt] = 0;

            else if (team_cnt == person_cnt)
                dp[team_cnt][person_cnt] = 1;

            else
                dp[team_cnt][person_cnt] = dp[team_cnt][person_cnt - 1] * team_cnt + dp[team_cnt - 1][person_cnt - 1];
        }

    cout << dp[k][n] << endl;
}

int main()
{
    cout << "Hello world!\n";
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

/*
5 3
*/

// 4
// 3