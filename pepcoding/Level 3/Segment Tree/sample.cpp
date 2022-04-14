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
// left and right are pointer to segment Tree and
// start and end is query range to get ans. asked by users.
// here we reduce search space of searching.
{

    // 1. No overlap
    if (right < start || left > end)
        return 0;

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

void update(int node, int left, int right, int pos, int val)
{
    if (pos < left || pos > right)
        return;

    if (left == right)
    {
        arr[pos] = val;
        segTree[node] = val;
    }

    else
    {
        int mid = (left + right) / 2;
        int left_node = 2 * node;
        int right_node = 2 * node + 1;

        if (pos >= left && pos <= mid)
            update(left_node, left, mid, pos, val);
        else if (pos >= mid + 1 && pos <= right)
            update(right_node, mid + 1, right, pos, val);

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
    // update(1, 0, arr.size() - 1, idx, val);
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
