// 1. You are given a number n, representing the number of envelopes.
// 2. You are given n pair of numbers, representing the width and height of each envelope.
// 3. You are required to print the count of maximum number of envelopes that can be nested inside each other.
// Note -> Rotation is not allowed.

#include "../header.h"

int solve(vii &envelop)
{
    sort(all(envelop), [=](pi a, pi b)
         { return a.se < b.se; });

    vi dp(envelop.size());
    int ans = 0;
    for (int i = 0; i < dp.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < i; j++)
            if (envelop[i].fs > envelop[j].fs)
                cnt = max(cnt, dp[j]);
        dp[i] = cnt + 1;
        ans = max(ans, dp[i]);
    }

    return ans;
}

int main()
{
    cout << "hello!\n";
    int n;
    cin >> n;
    vii arr(n);
    for (int i = 0; i < n; i++)
    {
        int l, b;
        cin >> l >> b;
        arr[i] = {l, b};
    }
    cout << "\n**************\n";
    cout << solve(arr);
    return 0;
}

/*
11
17 5
26 18
25 34
48 84
63 72
42 86
9 55
4 70
21 45
68 76
58 51
*/