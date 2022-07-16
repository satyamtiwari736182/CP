// 1. You are given a number n, representing the number of friends.
// 2. Each friend can stay single or pair up with any of it's friends.
// 3. You are required to print the number of ways in which these friends can stay single or pair up.
// E.g.
// 1 person can stay single or pair up in 1 way.
// 2 people can stay singles or pair up in 2 ways. 12 => 1-2, 12.
// 3 people (123) can stay singles or pair up in 4 ways. 123 => 1-2-3, 12-3, 13-2, 23-1.

#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    vi dp(n + 1);
    dp[1] = 1, dp[2] = 2;

    for (int frnd_cnt = 3; frnd_cnt <= n; frnd_cnt++)
        dp[frnd_cnt] = dp[frnd_cnt - 1] + dp[frnd_cnt - 2] * (frnd_cnt - 1);

    cout << dp[n] << endl;
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


// 4