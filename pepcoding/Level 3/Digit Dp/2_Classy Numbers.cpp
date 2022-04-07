//https://codeforces.com/problemset/problem/1036/C

#include "../header.h"

static ll dp[20][2][4];
static string str = "";

ll solver(int pos, bool bounded, ll count)
{
    if (pos == str.length())
        return 1;
    if (dp[pos][bounded][count] != -1)
        return dp[pos][bounded][count];
    int limit = 9;
    if (bounded == true)
        limit = str[pos] - '0';

    ll ans = 0;

    for (int i = 0; i <= limit; i++)
    {
        int updated_cnt = count + (i > 0 ? 1 : 0);
        if (updated_cnt <= 3)
            ans += solver(pos + 1, bounded && (i == limit), updated_cnt);
    }
    return dp[pos][bounded][count] = ans;
}
ll solve()
{
    ll l, r;
    cin >> l >> r;
    str = to_string(r);
    memset(dp, -1, sizeof(dp));
    ll rightCount = solver(0, true, 0);
    str = to_string(l - 1);
    memset(dp, -1, sizeof(dp));
    ll leftCount = solver(0, true, 0);
    return rightCount - leftCount;
}
int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    cin >> t;
    while (t-- > 0)
    {
        cout << "\n=================================\n";
        cout << solve();
        cout << "\n=================================\n";
    }
    return 0;
}

// 4

// 1 100
// 1 10
// 100 777
// 1 999