// You are given an array(of integers) of length n.
// You are required to answer q queries.

// Queries can be of two types
// 0. 0 l r : In this you have to return sum of all elements arr[i] for i in l<=i<=r.
// 1. 1 l r val: In this query u have to increase all elements in this interval [l, r] by val.

// To do the above task u have to create a datastructure as follows :-

// Implement the SegmentTree class:
// 1. SegmentTree(int arr[]): Initializes the SegmentTree object with an array,
// 2. void update(int l, int r, int val): increase all elements in this interval [l, r] by val,
// 3. int query(int l, int r): return sum of all elements arr[i] for which i is in range [l, r].

#include "../header.h"

vi arr, segTree, lazySeg;

void buildSegTree(int node, int left, int right)
{
    if (left == right)
        segTree[node] = arr[left];
    else
    {
        int mid = (left + right) / 2;
        int left_node = 2 * node;
        int right_node = 2 * node + 1;
        buildSegTree(left_node, left, mid);
        buildSegTree(right_node, mid + 1, right);

        segTree[node] = segTree[left_node] + segTree[right_node];
    }
}

void propagate(int node, int left, int right)
{
    if (left == right)
    {
        segTree[node] += lazySeg[node];
        lazySeg[node] = 0;
    }
    else
    {
        int total_node_subtree = right - left + 1;
        segTree[node] += total_node_subtree * lazySeg[node];

        int left_node = 2 * node;
        int right_node = 2 * node + 1;

        lazySeg[left_node] += lazySeg[node];
        lazySeg[right_node] += lazySeg[node];

        lazySeg[node] = 0;
    }
}

int query(int node, int left, int right, int start, int end)
{
    // propagate(node, left, right); //Even at this position propagation results no issues.

    // 1. No overlap
    if (right < start || left > end)
        return 0;

    propagate(node, left, right);

    // cout << " # " << left << " " << right << " #" << endl;

    // 2. Leaf or single node
    if (left == right)
        return segTree[node];

    // 3. Complete overlap of search-space with query range.
    else if (start <= left && right <= end)
        return segTree[node];

    // 4. Partial overlap
    else
    {
        int mid = (left + right) / 2;
        int left_node = 2 * node;
        int right_node = 2 * node + 1;

        int left_res = query(left_node, left, mid, start, end);
        int right_res = query(right_node, mid + 1, right, start, end);

        return left_res + right_res;
    }
}

void update(int node, int left, int right, int start, int end, int val)
{
    propagate(node, left, right); // this propaation has to be at this place

    if (right < start || left > end)
        return;

    if (left == right)
        segTree[node] += val;

    else if (start <= left && right <= end)
    {
        lazySeg[node] += val;
        propagate(node, left, right);
    }

    else
    {
        int mid = (left + right) / 2;
        int left_node = 2 * node;
        int right_node = 2 * node + 1;

        update(left_node, left, mid, start, end, val);
        update(right_node, mid + 1, right, start, end, val);

        segTree[node] = segTree[left_node] + segTree[right_node];
    }
}

//!=========================================

int Query(int left, int right)
{
    return query(1, 0, arr.size() - 1, left, right);
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
        if (type == 0)
        {
            int left, right;
            cin >> left >> right;
            int ans = Query(left, right);
            cout << ans << "  **\n";
        }
        else if (type == 1)
        {
            int left, right, val;
            cin >> left >> right >> val;
            Update(left, right, val);
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

    return 0;
}

// 8
// 0 10 10 -1 5 8 10 2
// 5
// 0 7 7
// 1 4 6 1
// 0 2 4
// 1 5 5 7
// 0 3 7
