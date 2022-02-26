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
    string str1, str2; // convert str1 -> str2
    int x, y;
    cin >> str1 >> str2;
    cin >> x >> y;
    str1 = " " + str1;
    str2 = " " + str2;
    int n1 = str1.length();
    int n2 = str2.length();

    int dp[n1][n2];
    fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), 0);

    //-----------------------------------------------------

    // Similar to ASCII cost character deletion program
    /*for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 0;
            else if (i == 0)
                dp[i][j] = y + dp[i][j - 1];
            else if (j == 0)
                dp[i][j] = x + dp[i - 1][j];
            else if (str1[i] == str2[j])
                dp[i][j] += dp[i - 1][j - 1];
            else
                dp[i][j] += min(x + dp[i - 1][j], y + dp[i][j - 1]);
        }*/

    //-----------------------------------------------------

    // Using LCS concept as deletion cost is constant from either of the string
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 0;
            else if (i == 0)
                dp[i][j] = 0;
            else if (j == 0)
                dp[i][j] = 0;
            else if (str1[i] == str2[j])
                dp[i][j] += 1 + dp[i - 1][j - 1];
            else
                dp[i][j] += max(dp[i - 1][j], dp[i][j - 1]);
        }

    //-----------------------------------------------------
    int lcs = dp[n1 - 1][n2 - 1];
    cout << "cost: " << (x * (n1 - 1 - lcs) + y * (n2 - 1 - lcs));
    cout << "\nHello world!\n";

    pmatrix(dp, n1, n2);
    return 0;
}

// pepcoder
// peerdcop
