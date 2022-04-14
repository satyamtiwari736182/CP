// You are given an array(of integers) of length n.
// You are required to answer q queries.

// Queries can be of two types
// 0. 0 ind : In this you have to tell the value of arr[ind].
// 1. 1 l r val: In this query u have to increase all elements in this interval [l, r] by val.

// To do the above task u have to create a datastructure as follows :-

// Implement the SegmentTree class:
// 1. SegmentTree(int arr[]): Initializes the SegmentTree object with an array,
// 2. void update(int l, int r, int val): increase all elements in this interval [l, r] by val,
// 3. int query(int ind): return arr[ind].

#include "../header.h"

vi arr, segTree, lazySeg;

void buildSegTree(int node, int left, int right)
{
    if (left == right)
        lazySeg[node] = arr[left];

    else
    {
        int mid = (left + right) / 2;
        int left_node = 2 * node;
        int right_node = 2 * node + 1;

        buildSegTree(left_node, left, mid);
        buildSegTree(right_node, mid + 1, right);
    }
}

void propagate(int node, int left, int right)
{
    if (left == right)
        return;
    int left_node = 2 * node;
    int right_node = 2 * node + 1;

    lazySeg[left_node] += lazySeg[node];
    lazySeg[right_node] += lazySeg[node];
    lazySeg[node] = 0;
}

int query(int node, int left, int right, int pos)
// left and right are pointer to segment Tree and
// here we reduce search space of searching.
{
    propagate(node, left, right);

    // Leaf or single node
    if (left == right)
        return lazySeg[node];

    else
    {
        int mid = (left + right) / 2;
        int left_node = 2 * node;
        int right_node = 2 * node + 1;

        if (pos >= left && pos <= mid)
            return query(left_node, left, mid, pos);
        else if (pos >= mid + 1 && pos <= right)
            return query(right_node, mid + 1, right, pos);
    }
}

void update(int node, int left, int right, int start, int end, int val)
{
    if (right < start || left > end)
        return;

    if (left == right)
        lazySeg[node] += val;

    else if (start <= left && right <= end)
        lazySeg[node] += val;

    else
    {
        int mid = (left + right) / 2;
        int left_node = 2 * node;
        int right_node = 2 * node + 1;

        update(left_node, left, mid, start, end, val);
        update(right_node, mid + 1, right, start, end, val);
    }
}

//!=========================================

int Query(int idx)
{
    return query(1, 0, arr.size() - 1, idx);
}

int Update(int left, int right, int val)
{
    update(1, 0, arr.size() - 1, left, right, val);
}

//!=========================================
void solve()
{
    int n;
    cin >> n;
    arr.resize(n);
    segTree.resize(4 * n);
    lazySeg.resize(4 * n);
    rarr(arr, 0, n);

    buildSegTree(1, 0, arr.size() - 1);

    //-------Query-------

    int q;
    cin >> q;
    test(q)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int left, right, val;
            cin >> left >> right >> val;
            Update(left, right, val);
        }
        else if (type == 0)
        {
            int idx;
            cin >> idx;
            int ans = Query(idx);
            cout << ans << "  **\n";
        }
    }
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
    parr(lazySeg, lazySeg.size());
    return 0;
}

// 8
// 4 3 9 3 9 8 7 2
// 5
// 1 4 6 0
// 0 7
// 1 0 3 4
// 0 4
// 0 5
