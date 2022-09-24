// https://leetcode.com/problems/xor-queries-of-a-subarray/


#include "../header.h"

vi sol(auto &arr, auto &queries)
{
    int n = arr.size();
    int prefix[n];
    memset(prefix, 0, sizeof(prefix));
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] ^ arr[i];

    vi res;
    for (int i = 0; i < queries.size(); i++)
    {
        int a = queries[i].fs;
        int b = queries[i].se;
        if (a == 0)
            res.pb(prefix[b]);
        else
            res.pb(prefix[b] ^ prefix[a - 1]);
    }
    return res;
}

int main()
{
    cout << "\nHello world!" << endl;
    int n, q;
    cin >> n;
    vi arr;
    rvarr(arr, 0, n);

    vector<pi> queries;
    cin >> q;

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        queries.pb({a, b});
    }
    cout << "\n========================================\n";
    vi res = sol(arr, queries);
    for (auto ans : res)
        cout << ans << " ";
    cout << "\n========================================\n";
    return 0;
}

// 4
// 1 3 4 8
// 4
// 0 1
// 1 2
// 0 3
// 3 3

// output:  2 7 14 8
