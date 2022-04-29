// You are given an array(of integers) of length n.
// You are required to answer q queries.

// Queries can be of two types :-
// Update
// 0 idx val : set arr[idx] to val.
// Query
// 1 l r: find i,j such that l <= i < j <= r, such that arr[i]+arr[j] is maximized. return arr[i]+arr[j].

#include "../header.h"

class Pair
{
public:
    Pair(int sum, int max) : sum(sum), max(max) {}
    int sum, max;
};

Pair calc(Pair left, Pair right)
{
    Pair ans(0, 0);

    ans.sum = max(left.sum, right.sum); // both values from left or right
    // else
    ans.sum = max(ans.sum, left.max + right.max);
    ans.max = max(left.max, right.max);
    return ans;
}

vector<Pair> segTree, lazySeg;
vi arr;

void buildSegTree(int node, int left, int right)
{
    if (left == right)
        segTree[node] = Pair(arr[left], arr[left]);
    else
    {
        int mid = (left + right) / 2;
        int left_node = 2 * node;
        int right_node = 2 * node + 1;
        buildSegTree(left_node, left, mid);
        buildSegTree(right_node, mid + 1, right);

        segTree[node] = calc(segTree[left_node], segTree[right_node]);
    }
}

Pair query(int node, int left, int right, int start, int end)
{
    // 1. No overlap
    if (right < start || left > end)
        return Pair(0, 0);

    // propagate(node, left, right);

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

        Pair left_res = query(left_node, left, mid, start, end);
        Pair right_res = query(right_node, mid + 1, right, start, end);

        return calc(left_res, right_res);
    }
}

void update(int node, int left, int right, int pos, int val)
{
    if (pos < left || pos > right)
        return;

    if (left == right)
    {
        arr[pos] = val;
        segTree[node] = Pair(val, val);
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

        segTree[node] = calc(segTree[left_node], segTree[right_node]);
    }
}

//!=========================================

int Query(int left, int right)
{
    Pair ans = query(1, 0, arr.size() - 1, left, right);
    return ans.sum;
}

int Update(int pos, int val)
{
    update(1, 0, arr.size() - 1, pos, val);
}

//!=========================================
void solve()
{
    int n;
    cin >> n;

    arr.resize(n);
    segTree.resize(4 * n, Pair(0, 0));
    lazySeg.resize(4 * n, Pair(0, 0));

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
            int left, right;
            cin >> left >> right;
            int ans = Query(left, right);
            cout << ans << "  **\n";
        }
        else if (type == 0)
        {
            int pos, val;
            cin >> pos >> val;
            Update(pos, val);
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
// 2 6 1 5 4 10 10 9
// 5
// 1 0 4
// 0 0 10
// 1 0 4
// 1 0 7
// 1 3 4
