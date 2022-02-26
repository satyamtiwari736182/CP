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

vector<string> sol(vi &arr)
{
    vector<string> res;
    sort(all(arr));
    int minXor = INT_MAX;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int Xor = arr[i] ^ arr[i + 1];
        if (Xor < minXor)
        {
            minXor = Xor;
            res.clear();
            res.pb(to_string(minXor));
            res.pb(to_string(arr[i]) + "-" + to_string(arr[i + 1]));
        }
        else if (Xor == minXor)
            res.pb(to_string(arr[i]) + "-" + to_string(arr[i + 1]));
    }
    return res;
}

int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;
    vi arr;
    rvarr(arr, 0, n);
    cout << "\n========================================\n";
    vector<string> pairs = sol(arr);

    for (auto pr : pairs)
        cout << pr << ", ";

    // 1, 6 - 7, 8 - 9, 14 - 15,
    // cout << (6 ^ 7) << "\t" << (8 ^ 9) << "\t" << (14 ^ 15) << endl;
    cout << "\n========================================\n";
    return 0;
}

// 11
// 5 15 7 3 18 9 8 16 12 14 6