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

int sol(string str1, string str2, int i, int j)
{

    if (i == 0)
        return j;
    if (j == 0)
        return i;

    if (str1[i - 1] == str2[j - 1])
        return sol(str1, str2, i - 1, j - 1);

    return 1 + min(sol(str1, str2, i, j - 1),
                   min(sol(str1, str2, i - 1, j),
                       sol(str1, str2, i - 1, j - 1)));
}
int main()
{
    string str1, str2; // convert str1 -> str2
    cin >> str1 >> str2;
    str1 = " " + str1;
    str2 = " " + str2;
    int n1 = str1.length();
    int n2 = str2.length();

    cout << sol(str1, str2, n1, n2) << endl;

    int dp[n1][n2];
    fill(*dp, *dp + n1 * n2, 0);
    //-----------------------------------------------------

    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 0;
            else if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else
            {
                if (str1[i] == str2[j])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j],
                                       min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }

    //-----------------------------------------------------

    cout << "\nHello world!\n";
    pmatrix(dp, n1, n2);
    return 0;
}

// abcd
// aebd
