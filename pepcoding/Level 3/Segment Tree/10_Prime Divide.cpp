// You are given an array A of N numbers.
// You need to perform Q operations. Each operation has one of the two type:

// 1. 1 l r p: select all numbers between indices l to r which are divisible by p and  divide then all by p, here is in set {2, 3, 5}.
// 2. 2 l d: update element at index l to d.

// Print the final array after performing all operations.

// You are given an array(of integers) of length n.
// You are required to answer q queries.

// Queries can be of two types :-
// Update
// 0 idx val : set arr[idx] to val.
// Query
// 1 l r: find i,j such that l <= i < j <= r, such that arr[i]+arr[j] is maximized. return arr[i]+arr[j].

#include "../header.h"

int **lazySeg;
vi arr;

void calc(int *childNode, int *node)
{
    int result[3];
    for (int i = 0; i < 3; i++)
        childNode[i] += node[i];
}

int reduce(int val, int *prime)
{
    while (val % 2 == 0 && prime[0])
    {
        prime[0]--;
        val /= 2;
    }

    while (val % 3 == 0 && prime[1])
    {
        prime[1]--;
        val /= 3;
    }

    while (val % 5 == 0 && prime[2])
    {
        prime[2]--;
        val /= 5;
    }

    return val;
}

void propagate(int node, int left, int right)
{
    if (left != right)
    {
        int leftNode = 2 * node;
        int rightNode = 2 * node + 1;
        calc(lazySeg[leftNode], lazySeg[node]);
        calc(lazySeg[rightNode], lazySeg[node]);
    }

    else
        arr[left] = reduce(arr[left], lazySeg[node]);

    for (int i = 0; i <= 2; i++)
        lazySeg[node][i] = 0;
}

void propagateAll(int node, int left, int right)
{
    propagate(node, left, right);
    if (left == right)
        return;
    int mid = (left + right) / 2;
    propagateAll(node * 2, left, mid);
    propagateAll(node * 2 + 1, mid + 1, right);
}

void update(int node, int left, int right, int start, int end, int idx)
{
    if (right < start || left > end)
        return;

    if (start <= left && right <= end)
        lazySeg[node][idx]++;

    else
    {
        int mid = (left + right) / 2;
        int left_node = 2 * node;
        int right_node = 2 * node + 1;

        update(left_node, left, mid, start, end, idx);
        update(right_node, mid + 1, right, start, end, idx);
    }
}

void update(int node, int left, int right, int pos, int val)
{
    propagate(node, left, right);

    if (left == right)
        arr[pos] = val;
    else
    {
        int mid = (left + right) / 2;
        int left_node = 2 * node;
        int right_node = 2 * node + 1;

        if (pos >= left && pos <= mid)
            update(left_node, left, mid, pos, val);
        else if (pos >= mid + 1 && pos <= right)
            update(right_node, mid + 1, right, pos, val);
    }
}

//!=========================================

int UpdateR(int left, int right, int idx) // range update
{
    update(1, 1, arr.size() - 1, left, right, idx);
}

int UpdateP(int pos, int val) // point update
{
    update(1, 1, arr.size() - 1, pos, val);
}

//!=========================================
void solve()
{
    int n;
    cin >> n;

    arr.resize(n + 1);
    rarr(arr, 1, arr.size());

    lazySeg = new int *[4 * n];
    int i = 0, j = 0;
    REP(i, 0, 4 * n)
    lazySeg[i] = new int[3];

    i = 0;
    REP(i, 0, 4 * n)
    REP(j, 0, 3)
    lazySeg[i][j] = 0;

    //-------Query-------
    int q;
    cin >> q;
    test(q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int left, right, div, idx = 0;
            cin >> left >> right >> div;
            idx = div == 2 ? 0 : (div == 3 ? 1 : 2);

            UpdateR(left, right, idx); // Range update
        }
        else if (type == 2)
        {
            int val, pos;
            cin >> pos >> val;
            UpdateP(pos, val); // point update
        }
    }

    propagateAll(1, 1, n);

    i = 0;
    REP(i, 1, arr.size())
    cout << arr[i] << " ";

    cout << endl;
    // pmatrix(lazySeg, 4 * n, 3);
}

int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    // cin >> t;
    test(t)
    {
        solve();
        cout << "\n------------------------------\n";
    }

    return 0;
}

// 5
// 8 9 12 3 5
// 5
// 1 1 5 3
// 2 5 9
// 1 1 5 3
// 1 2 5 2
// 2 3 5

// ? 8 1 5 1 3
//!================================

// int m = 5, n = 4, c = 0;
//     int **a;

//     a = new int *[m];

//     for (int i = 0; i < m; i++)
//         a[i] = new int[n];

//     int i = 0, j = 0;
//     REP(i, 0, m)
//     REP(j, 0, n)
//     a[i][j] = ++c;
//     int reset[] = {0, 0, 0, 0};
//     a[2] = reset;
//     pmatrix(a, m, n);

//!================================
