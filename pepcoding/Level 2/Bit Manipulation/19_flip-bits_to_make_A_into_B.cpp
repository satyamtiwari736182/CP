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
#define vs vector<string>
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
    cout << "\nHello world!" << endl;

    int a, b;
    cin >> a >> b;
    cout << "\n========================================\n";
    int bit_diff = a ^ b;
    int count = 0;
    while (bit_diff > 0)
    {
        count++;
        bit_diff -= (bit_diff & -bit_diff);
    }
    cout << "Num. of flip required: " << count;

    cout << "\n========================================\n";
    return 0;
}