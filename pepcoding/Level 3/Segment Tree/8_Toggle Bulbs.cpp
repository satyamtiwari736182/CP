// You are given n bulbs, numbered from 1 to n. Initially all the bulbs are turned off.
// You have to perform 2 types of operations:-

// 1. Toggle all bulds numbered between A to B.Here toggle mean turn on bulbs to off and off bulbs to on.This is represented by 1 A B.
// 2. Count how many bulbs numbered between A to B are on.This is represented by 2 A B.



#include "../header.h"
vi arr, segTree, lazySeg;

void propagate(int node, int left, int right)
{
    if (lazySeg[node] == 0)
        return;

    if (left == right)
    {
        segTree[node] ^= lazySeg[node];
        lazySeg[node] = 0;
    }
    else
    {
        int total_node_subtree = right - left + 1;
        segTree[node] = total_node_subtree - lazySeg[node];

        int left_node = 2 * node;
        int right_node = 2 * node + 1;

        lazySeg[left_node] ^= lazySeg[node];
        lazySeg[right_node] ^= lazySeg[node];

        lazySeg[node] = 0;
    }
}

int query(int node, int left, int right, int start, int end)
{

    // 1. No overlap
    if (right < start || left > end)
        return 0;

    propagate(node, left, right);

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

void update(int node, int left, int right, int start, int end)
{
    propagate(node, left, right); // this propaation has to be at this place

    if (right < start || left > end)
        return;

    if (left == right)
        segTree[node] ^= 1;

    else if (start <= left && right <= end)
    {
        lazySeg[node] ^= 1;
        propagate(node, left, right);
    }

    else
    {
        int mid = (left + right) / 2;
        int left_node = 2 * node;
        int right_node = 2 * node + 1;

        update(left_node, left, mid, start, end);
        update(right_node, mid + 1, right, start, end);

        segTree[node] = segTree[left_node] + segTree[right_node];
    }
}

//!=========================================

int Query(int left, int right)
{
    return query(1, 1, arr.size() - 1, left, right);
}

int Update(int left, int right)
{
    update(1, 1, arr.size() - 1, left, right);
}

//!=========================================
void solve()
{
    int n;
    cin >> n; // number of bulbs from 1....n

    arr.resize(n + 1);
    segTree.resize(4 * n);
    lazySeg.resize(4 * n);

    //-------Query-------
    int q;
    cin >> q;
    test(q)
    {
        int type;
        cin >> type;
        if (type == 2)
        {
            int left, right;
            cin >> left >> right;
            int ans = Query(left, right); // get all " on " bulbs
            cout << ans << "  **\n";
        }
        else if (type == 1)
        {
            int left, right;
            cin >> left >> right;
            Update(left, right); // toggle the bulbs.
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

// 4 7
// 2 1 4
// 1 2 3
// 2 1 2
// 2 1 1
// 1 1 4
// 2 1 4
// 2 4 4