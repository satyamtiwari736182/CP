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

class Pair
{
public:
    int i, lent;
    string psf;
    Pair(int i, int lent, string psf)
    {
        this->i = i;
        this->lent = lent;
        this->psf = psf;
    }
};

int main()
{
    int n;
    cin >> n;

    int arr[n], dp[n], lent = 1, pos = 0;
    fill(dp, dp + n, 0);
    rarr(arr, 0, n);
    dp[0] = 1;

    //------------------------------------------------------
    for (int i = 1; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < i; j++)
            if (arr[i] >= arr[j])
                count = max(count, dp[j]);
        dp[i] = count + 1;

        if (dp[i] > lent)
        {
            lent = dp[i];
            pos = i;
        }
    }
    //------------------------------------------------------
    cout << "\n"
         << lent << endl;
    queue<Pair> que;
    que.push(Pair(pos, lent, to_string(arr[pos])));
    while (!que.empty())
    {
        Pair temp = que.front();
        if (temp.lent == 1)
            cout << temp.psf << "." << endl;
        for (int i = temp.i; i >= 0; i--)
            if (dp[i] == temp.lent - 1 && arr[i] <= arr[temp.i])
                que.push(Pair(i, temp.lent - 1, to_string(arr[i]) + " -> " + temp.psf));
        que.pop();
    }

    cout << "\nHello world!\n";

    return 0;
}

// 10
// 10 22 9 33 21 50 41 60 80 1
