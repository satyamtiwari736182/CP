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
    int dp[n][n];
    fill(*dp, *dp + n * n, 0);

    //-----------------------------------------------------

    for (int g = 0; g < n; g++)
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
                dp[i][j] = 0;
            else if (g == 1)
            {
                char ch1 = str[i];
                char ch2 = str[j];
                if (ch1 != ch2)
                    dp[i][j] = 1;
            }
            else
            {
                char ch1 = str[i];
                char ch2 = str[j];

                if (ch1 == ch2)
                    dp[i][j] = dp[i + 1][j - 1];

                else
                {
                    int val = INT_MAX;
                    for (int k = 0; k < j; k++)
                        val = min(val, 1 + dp[i][k] + dp[k + 1][j]);
                    dp[i][j] = val;
                }
            }
        }

    //-----------------------------------------------------

    cout << "\nHello world!\n";
    pmatrix(dp, n, n);
    return 0;
}

// 8
// 1 5 8 9 10 17 17 20
