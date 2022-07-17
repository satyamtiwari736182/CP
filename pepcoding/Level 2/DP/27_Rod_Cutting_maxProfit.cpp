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
    int n;
    cin >> n;
    int arr[n + 1], dp[n + 1];
    arr[0] = 0;
    rarr(arr, 1, n + 1);

    for (int i = 0; i < n + 1; i++)
        dp[i] = arr[i];

    //-----------------------------------------------------
    for (int i = 1; i < n + 1; i++)
        for (int j = 0; j <= i / 2; j++)
            dp[i] = max(dp[i], dp[i - j] + dp[j]);
    //-----------------------------------------------------

    cout << "\nHello world!\n";
    parr(arr, n + 1);
    cout << "\n*******************************\n";
    parr(dp, n + 1);

    return 0;
}

// 8
// 1 5 8 9 10 17 17 20
