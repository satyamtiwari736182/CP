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

int sol(int n)
{
    bool flag = false;
    int rev = 0;
    int j = 0;

    for (int i = 31; i >= 0; i--)
    {
        int mask = (1 << i);

        if (flag)
        {
            if ((n & mask) != 0)
            {
                cout << 1;
                int smask = (1 << j);
                rev |= smask;
            }
            else
                cout << 0;
            j++;
        }

        else if ((n & mask) != 0)
        {
            flag = true;
            cout << 1;
            int smask = (1 << j);
            rev |= smask;
            j++;
        }
    }

    return rev;
}
int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;

    cout << "\n========================================\n";
    bitset<32> val(n);
    cout << val << endl;

    int rev = sol(n);
    bitset<32> val2(rev);
    cout << endl
         << rev << endl
         << val2;
    cout << "\n========================================\n";
    return 0;
}
