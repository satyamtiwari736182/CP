#include <bits/stdc++.h>
using namespace std;

#define REP(a, b) for (int i = a; i <= b; i++)
#define REP2(i, a, b) for (i = a; i <= b; i++)

#define rarr(arr, l, r)         \
    for (int i = l; i < r; i++) \
        cin >> arr[i];

#define rvarr(arr, l, r)        \
    for (int i = l; i < r; i++) \
    {                           \
        int val;                \
        cin >> val;             \
        arr.push_back(val);     \
    }

#define parr(arr, n)            \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";

#define rmatrix(arr, n, m)          \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
            cin >> arr[i][j];

#define rvmatrix(arr, n, m)         \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
        {                           \
            int val;                \
            cin >> val;             \
            arr[i].push_back(val);  \
        }

#define pmatrix(arr, n, m)            \
    for (int i = 0; i < n; i++)       \
    {                                 \
        for (int j = 0; j < m; j++)   \
            cout << arr[i][j] << " "; \
        cout << endl;                 \
    }

#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define ll long long
#define fs first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define mod 1000000007
const int INF = 1e9 + 7;
const double PI = 3.141592653589793238;
const int M = 100, N = 100;

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
