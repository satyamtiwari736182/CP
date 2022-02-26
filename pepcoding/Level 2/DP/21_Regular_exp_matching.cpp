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
    string str, pattern;
    cin >> str >> pattern;
    str = " " + str;
    pattern = " " + pattern;
    int n1 = str.length();
    int n2 = pattern.length();
    bool dp[n2][n1];
    fill(*dp, *dp + n1 * n2, 0);

    //-----------------------------------------------------
    for (int i = 0; i < n2; i++)
        for (int j = 0; j < n1; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else if (j == 0)
            {
                if (pattern[i] == '*')
                    dp[i][j] = dp[i - 2][j];
                else
                    dp[i][j] = false;
            }
            else
            {
                if (pattern[i] == '*')
                {
                    dp[i][j] = dp[i - 2][j];
                    if (pattern[i - 1] == str[j] || pattern[i - 1] == '.')
                        dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
                else if (pattern[i] == str[j] || pattern[i] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = false;
            }
        }

    //-----------------------------------------------------

    cout << "\nHello world!\n";
    pmatrix(dp, n2, n1);
    return 0;
}

// abcbac
