#include <bits/stdc++.h>
using namespace std;

#define REP(a, b) for (int i = a; i <= b; i++)
#define REP2(i, a, b) for (i = a; i <= b; i++)

#define rarr(arr, l, r)         \
    for (int i = l; i < r; i++) \
        cin >> arr[i];

#define rvarr(arr, l, r)        \
    for (int i = l; i < r; i++) \
    {                           \
        int val;                \
        cin >> val;             \
        arr.push_back(val);     \
    }

#define parr(arr, n)            \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";

#define rmatrix(arr, n, m)          \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
            cin >> arr[i][j];

#define rvmatrix(arr, n, m)         \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
        {                           \
            int val;                \
            cin >> val;             \
            arr[i].push_back(val);  \
        }

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

int minflips(int a, int b, int c)
{
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        int mask = 1 << i;
        int ai = a & mask ? true : 0;
        int bi = b & mask ? true : 0;
        int ci = c & mask ? true : 0;

        if (ci == true)
        {
            if (!ai && !bi) // any one must be true for ' a or b '
                ans++;
        }

        else
        {
            if (ai && bi)
                ans += 2;
            else if (ai || bi)
                ans++;
        }
    }
    return ans;
}

int main()
{
    cout << "\nHello world!" << endl;
    int a, b, c;
    cin >> a >> b >> c;
    cout << "\n========================================\n";
    cout << minflips(a, b, c);
    cout << "\n========================================\n";
    return 0;
}

// 4 2 7
// o:1

// 1 2 3
// o:0
