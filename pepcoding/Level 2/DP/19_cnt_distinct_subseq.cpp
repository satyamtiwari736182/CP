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
    string str;
    cin >> str;
    int n = str.length();
    int dp[n + 1];
    fill(dp, dp + n + 1, 0);

    map<char, int> hashmap;

    dp[0] = 1;
    //-----------------------------------------------------
    for (int i = 0; i < n; i++)
    {
        if (hashmap.find(str[i]) != hashmap.end())
        {
            dp[i + 1] = 2 * dp[i] - dp[hashmap.at(str[i])];
            hashmap[str[i]] = i;
        }
        else
        {
            dp[i + 1] = 2 * dp[i];
            hashmap[str[i]] = i;
        }
    }
    //-----------------------------------------------------

    cout << "\nHello world!\n";

    parr(dp, n + 1);
    return 0;
}

// abcbac
