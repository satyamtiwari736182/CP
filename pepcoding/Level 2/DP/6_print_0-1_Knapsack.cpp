#include <bits/stdc++.h>
using namespace std;
#define REP(a, b) for (int i = a; i <= b; i++)
#define REP2(i, a, b) for (i = a; i <= b; i++)
#define rarr(arr, l, r)         \
    for (int i = l; i < r; i++) \
        cin >> arr[i];
#define parr(arr, n)            \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";
#define rmatrix(arr, n, m)          \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
            cin >> arr[i][j];
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

int main()
{
    int n, cap;
    cin >> n;
    int wt[n + 1] = {0}, prof[n + 1] = {0};
    rarr(prof, 1, n + 1);
    rarr(wt, 1, n + 1);
    cin >> cap;
    int dp[n + 1][cap + 1];

    fill(*dp, *dp + (n + 1) * (cap + 1), 0);

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= cap; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (wt[i] > j)
                dp[i][j] = dp[i - 1][j];

            else
                dp[i][j] = max(dp[i - 1][j], prof[i] + dp[i - 1][j - wt[i]]);
        }

    cout << "\n***********************\n"
         << dp[n][cap]
         << endl;
    pmatrix(dp, n + 1, cap + 1);

    return 0;
}

// 5
// 15 14 10 45 30
// 2 5 1 3 4
// 7
