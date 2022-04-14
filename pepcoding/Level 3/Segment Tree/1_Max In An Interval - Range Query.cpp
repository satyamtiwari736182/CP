// You are given an array(of integers) of length n.
// You are required to answer q queries.
// In each query u are given an interval l, r both inclusive and u have to find the maximum element in this interval.

// To do the above task u have to create a datastructure as follows :-

// Implement the SegmentTree class:
// 1. SegmentTree(int arr[]): Initializes the SegmentTree object with an array,
// 2. int query(int l, int r): return max in interval [l, r].

// Can u do it in O(log(n)) or better Time Complexity.

#include "../header.h"

vi arr, segTree;

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

        segTree[node] = max(segTree[left_node], segTree[right_node]);
    }
}

int query(int node, int left, int right, int start, int end)
// left and right are pointer to segment Tree and
// start and end is query range to get ans. asked by users.
// here we reduce search space of searching.
{

    // 1. No overlap
    if (right < start || left > end)
        return INT_MIN;

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

        return max(left_res, right_res);
    }
}

int Query(int left, int right)
{
    return query(1, 0, arr.size() - 1, left, right);
}
void solve()
{
    int n;
    cin >> n;
    arr.resize(n);
    segTree.resize(4 * n);
    rarr(arr, 0, n);

    buildSegTree(1, 0, arr.size() - 1);

    //-------Query-------
    int q;
    cin >> q;
    test(q)
    {
        int left, right;
        cin >> left >> right;
        int ans = Query(left, right);
        cout << ans << "  **\n";
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
// 8 7 4 2 5 3 1 10
// 4
// 0 7
// 0 3
// 2 7
// 1 6