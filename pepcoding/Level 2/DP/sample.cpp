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
const int M = 80, N = 80;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    rarr(arr, 0, n);
    int k;
    cin >> k;
    int dp[n] = {0};
    //-----------------------------------------------------

    int mx = 0, temp = k;

    for (int i = 0; i < n; i++)
    {
        
    }

    //-----------------------------------------------------
    cout << "\nHello world!\n";
    return 0;
}

// 18
// 4 3 -2 6 -14 7 -1 4 5 7 -10 2 9 -10 -5 -9 6 1
// 4

// 5
// 3 -2 -3 1 2
// 4
