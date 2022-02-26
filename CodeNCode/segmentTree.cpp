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

int buildTree(int *seg, int *arr, int idx, int l, int r)
{
    if (l > r)
        return INT_MAX;
    if (l == r)
    {
        seg[idx] = arr[l];
        return seg[idx];
    }
    int mid = l + (r - l) / 2;
    int left = buildTree(seg, arr, 2 * idx, l, mid);
    int right = buildTree(seg, arr, 2 * idx + 1, mid + 1, r);
    seg[idx] = min(left, right);
    return seg[idx];
}

int query(int *seg, int idx, int s, int e, int qs, int qe)
{
    // 1. No overlap Condition
    if (s > qe || e < qs)
        return INT_MAX;

    // 2. Completely Overlap Condition
    else if (qs <= s && qe >= e)
        return seg[idx];

    // 3. Partially Overlap Condition
    else
    {
        int mid = (e + s) / 2;

        int left = query(seg, 2 * idx, s, mid, qs, qe);
        int right = query(seg, 2 * idx + 1, mid + 1, e, qs, qe);

        return min(left, right);
    }
    return INT_MAX;
}

void updateNode(int *seg, int index, int s, int e, int i, int val)
{
    // No overlap
    if (i < s || i > e)
        return;

    // Reached leaf Node
    if (s == e)
    {
        seg[index] = val;
        return;
    }

    // Laying in Range
    int mid = (s + e) / 2;
    updateNode(seg, 2 * index, s, mid, i, val);
    updateNode(seg, 2 * index + 1, mid + 1, e, i, val);

    seg[index] = min(seg[2 * index], seg[2 * index + 1]);
    return;
}

void updateRange(int *seg, int index, int s, int e, int rs, int re, int inc)
{
    // No overlap
    if (re < s || rs > e)
        return;

    // Reached leaf Node
    if (s == e)
    {
        seg[index] += inc;
        return;
    }

    // Laying in Range
    int mid = (s + e) / 2;
    updateRange(seg, 2 * index, s, mid, rs, re, inc);
    updateRange(seg, 2 * index + 1, mid + 1, e, rs, re, inc);

    seg[index] = min(seg[2 * index], seg[2 * index + 1]);
    return;
}

void lazyUpdate(int *seg, int *lazy, int idx, int low, int high, int l, int r, int val)
// Range Updates for prefix-sum problem
{
    if (r < low || l > high || low > high)
        return;

    if (lazy[idx] != 0)
    {
        seg[idx] += (high - low + 1) * lazy[idx];
        if (low != high)
        {
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if (low >= l && high <= r)
    {
        seg[idx] += (high - low + 1) * lazy[idx];
        if (low != high)
        {
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }
        lazy[idx] = 0;
        return;
    }
    int mid = (low + high) >> 1;
    lazyUpdate(seg, lazy, 2 * idx, low, mid, l, r, val);
    lazyUpdate(seg, lazy, 2 * idx + 1, mid + 1, high, l, r, val);
    seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}

int main()
{
    int arr[] = {1, 3, 2, -2, 2, 3, -11};
    int n = sizeof(arr) / sizeof(*arr);

    int seg[4 * n + 5] = {0};

    int idx = 1, l = 0, r = n - 1;
    buildTree(seg, arr, idx, l, r);

    // updateNode(seg, idx, l, r, 6, 2);
    updateRange(seg, idx, l, r, 4, 6, 2);

    print(seg, 0, 4 * n + 3);
    // -2 1 -2 1 2 -2 5 1 3 0 0 -2 4

    cout << endl
         << query(seg, idx, l, r, 4, 6) << endl;
    //-------------------------------------------------------------
    // Lazy operations
    int lazy[n + 1] = {0};

    cout << "\nhello!  " << endl;
    return 0;
}
