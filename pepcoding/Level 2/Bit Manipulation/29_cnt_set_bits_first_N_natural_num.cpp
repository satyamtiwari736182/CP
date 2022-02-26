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
int largestPowerOf_2_inRange(int n)
{
    int x = 0;
    while ((1 << x) <= n)
        ++x;
    return x - 1; // returns the index not the original count from 1 insted from 0 as bollowed in binary number inddexing
}
int sol(int n)
{
    if (n == 0)
        return 0;
    int x = largestPowerOf_2_inRange(n);
    int bit_cnt_2x = (1 << (x - 1)) * x;
    int cnt_msbit_of_rest = n - (1 << x) + 1;
    int rest = n - (1 << x);

    int ans = bit_cnt_2x + cnt_msbit_of_rest + sol(rest);
    return ans;
}
int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;
    cout << "\n========================================\n";
    cout << sol(n);
    cout << "\n========================================\n";
    return 0;
}
