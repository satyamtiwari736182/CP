#include <bits/stdc++.h>
using namespace std;
#define REP(a, b) for (int i = a; i <= b; i++)
#define REP2(i, a, b) for (i = a; i <= b; i++)
#define print(arr, l, r)         \
    for (int i = l; i <= r; i++) \
        cout << arr[i] << " ";
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
void update(int *fen, int n, int idx, int val)
{
    while (idx < n)
    {
        fen[idx] += val;
        idx += (idx & (-idx));
    }
}

int sum(int *fen, int idx)
{
    int sum = 0;
    while (idx > 0)
    {
        sum += fen[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int rangeSum(int *fen, int l, int r)
{
    return sum(fen, r) - sum(fen, l - 1);
}

// Binary lifting
int find(int *fen, int n, int k)
// finding prefix sum <= k
{
    if (k > fen[n - 1])
        return fen[n - 1];

    int curr = 0, ans = 0, prrevsum = 0;
    for (int i = log2(n); i >= 0; i--)
    {
        if (fen[curr + (1 << i)] + prrevsum <= k)
        {
            curr = curr + (1 << i);
            prrevsum += fen[curr];
        }
    }
    return prrevsum;
}

int main()
{
    int arr[] = {1, 0, 2, 1, 1, 3, 0, 4, 2, 5, 2, 2, 3, 1, 0, 2, 0};
    int n = sizeof(arr) / sizeof(*arr);
    int fen[n + 1] = {0};
    int pre[n + 1] = {0};
    int suff[n + 1] = {0};

    int sof = 0;
    for (int i = 0; i <= n; i++)
    {
        sof += arr[i];
        pre[i + 1] = sof;
        // fen[i] = INT_MAX;
    }
    sof = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sof += arr[i];
        suff[i + 1] = sof;
    }

    // Build Fenwick( Binary Index Tree )
    for (int i = 1; i < n; i++)
        update(fen, n, i, arr[i - 1]);

    // Display fenwick tree
    for (int i = 1; i < n; i++)
        cout << fen[i] << " ";

    cout << "\nhello!  " << find(fen, n, 729) << endl;
    //
    return 0;
}