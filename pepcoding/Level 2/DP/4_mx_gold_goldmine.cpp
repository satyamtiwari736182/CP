#include <bits/stdc++.h>
using namespace std;
#define REP(a, b) for (int i = a; i <= b; i++)
#define REP2(i, a, b) for (i = a; i <= b; i++)
#define rarr(arr, l, r)          \
    for (int i = l; i <= r; i++) \
        cin >> arr[i];
#define parr(arr, l, r)          \
    for (int i = l; i <= r; i++) \
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

class Pair
{
public:
    int i, j;
    string path;
    Pair(int ii, int jj, string ppath)
    {
        i = ii;
        j = jj;
        path = ppath;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    
    int arr[n + 1][m + 1], dp[n + 1][m + 1];

    fill(*dp, *dp + (n + 1) * (m + 1), 0);
    rmatrix(arr, n, m);

    for (int j = m - 1; j >= 0; j--)
        for (int i = n - 1; i >= 0; i--)
        {
            if (j == m - 1)
                dp[i][j] = arr[i][j];

            else if (i == 0)
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], dp[i + 1][j + 1]);

            else if (i == n - 1)
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], dp[i - 1][j + 1]);

            else
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], max(dp[i + 1][j + 1], dp[i - 1][j + 1]));
        }

    int mxgold = 0;

    for (int i = 0; i < n; i++)
        mxgold = max(mxgold, *dp[i]);

    cout << "\n*****************************\n";
    cout << mxgold << endl;

    queue<Pair> que;

    for (int i = 0; i < n; i++)
        if (*dp[i] == mxgold)
            que.push(Pair(i, 0, "row " + to_string(i)));

    while (!que.empty())
    {
        Pair temp = que.front();
        if (temp.j == m - 1)
            cout << temp.path << "." << endl;

        else if (temp.i == 0)
        {
            int g = max(dp[temp.i][temp.j + 1], dp[temp.i + 1][temp.j + 1]);

            if (g == dp[temp.i][temp.j + 1])
                que.push(Pair(temp.i, temp.j + 1, temp.path + " d2"));

            if (g == dp[temp.i + 1][temp.j + 1])
                que.push(Pair(temp.i + 1, temp.j + 1, temp.path + " d3"));

        }

        else if (temp.i == n - 1)
        {

            int g = max(dp[temp.i][temp.j + 1], dp[temp.i - 1][temp.j + 1]);
            
            if (g == dp[temp.i - 1][temp.j + 1])
                que.push(Pair(temp.i - 1, temp.j + 1, temp.path + " d1"));

            if (g == dp[temp.i][temp.j + 1])
                que.push(Pair(temp.i, temp.j + 1, temp.path + " d2"));

        }

        else
        {
            int g = max(dp[temp.i][temp.j + 1], max(dp[temp.i + 1][temp.j + 1], dp[temp.i - 1][temp.j + 1]));

            if (g == dp[temp.i - 1][temp.j + 1])
                que.push(Pair(temp.i - 1, temp.j + 1, temp.path + " d1"));

            if (g == dp[temp.i][temp.j + 1])
                que.push(Pair(temp.i, temp.j + 1, temp.path + " d2"));

            if (g == dp[temp.i + 1][temp.j + 1])
                que.push(Pair(temp.i + 1, temp.j + 1, temp.path + " d3"));

        }

        que.pop();
    }
    cout << "\n*****************************\n";

    pmatrix(dp, n, m);
    return 0;
}

// 6
// 6
// 0 1 4 2 8 2
// 4 3 6 5 0 4
// 1 2 4 1 4 6
// 2 0 7 3 2 2
// 3 1 5 9 2 4
// 2 7 0 8 5 1
