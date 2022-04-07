
#include "../header.h"

int arr[100000];
ll dp[11][100][2];

ll getSum(int pos, ll n, ll sum, bool flag)
{
    if (pos > n)
        return sum;

    if (dp[pos][sum][flag] != -1)
        return dp[pos][sum][flag];

    ll res = 0;
    int limit = 9;
    if (!flag)
        limit = arr[pos];
    for (int i = 0; i <= limit; i++)
    {
        if (flag || i < limit)
            res += getSum(pos + 1, n, sum + i, true);
        else
            res += getSum(pos + 1, n, sum + i, false);
    }

    return dp[pos][sum][flag] = res;
}

ll sumofdigit(string n)
{
    ll ans = 0;
    for (char val : n)
        ans += val - '0';
    return ans;
}

int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    cin >> t;
    while (t-- > 0)
    {
        cout << "\n=================================\n";
        string l, r;

        cin >> l >> r;

        memset(dp, -1, sizeof(dp));
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < l.length(); i++)
            arr[i + 1] = l[i] - '0';

        ll leftsum = getSum(1, l.length(), 0, false);

        memset(dp, -1, sizeof(dp));
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < r.length(); i++)
            arr[i + 1] = r[i] - '0';

        ll rightsum = getSum(1, r.length(), 0, false);

        ll ans = rightsum - leftsum + sumofdigit(l);
        cout << ans << endl;
        cout << "\n=================================\n";
    }
    return 0;
}

// 4

// 1 100
// 1 10
// 100 777
// 1 999