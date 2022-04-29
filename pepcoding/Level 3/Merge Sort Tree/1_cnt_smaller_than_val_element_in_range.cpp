// !=======  Similar to Segment Tree =========

/*
Given an array of size N and Q queries of form L R val, find number of elements in the range L to R which are strictly smaller than  val.
*/

#include "../header.h"
vi mergeTree[4 * 1000];
int arr[1000];

void buildMergeTree(int node, int left, int right)
{
    if (left == right)
    {
        mergeTree[node].pb(arr[left]);
        return;
    }
    int mid = (left + right) / 2;
    int leftNode = 2 * node;
    int rightNode = 2 * node + 1;
    buildMergeTree(leftNode, left, mid);
    buildMergeTree(rightNode, mid + 1, right);

    // now merging two list on node.
    int i = 0, j = 0;

    while (i < mergeTree[leftNode].size() && j < mergeTree[rightNode].size())
    {
        if (mergeTree[leftNode][i] <= mergeTree[rightNode][j])
            mergeTree[node].pb(mergeTree[leftNode][i]), i++;
        else
            mergeTree[node].pb(mergeTree[rightNode][j]), j++;
    }

    while (i < mergeTree[leftNode].size())
        mergeTree[node].pb(mergeTree[leftNode][i]), i++;

    while (j < mergeTree[rightNode].size())
        mergeTree[node].pb(mergeTree[rightNode][j]), j++;
}

int query(int node, int left, int right, int start, int end, int val)
{
    if (right < start || left > end)
        return 0;
    if (start <= left && right <= end)
    {
        int res = upper_bound(all(mergeTree[node]), val - 1) - mergeTree[node].begin();
        return res;
    }

    else
    {
        int mid = (left + right) / 2;
        int leftNode = 2 * node;
        int rightNode = 2 * node + 1;
        int left_res = query(leftNode, left, mid, start, end, val);
        int right_res = query(rightNode, mid + 1, right, start, end, val);
        return left_res + right_res;
    }
}

void solve()
{
    int n, q, left, right, val;
    cin >> n >> q;
    rarr(arr, 1, n + 1);

    buildMergeTree(1, 1, n);

    test(q)
    {
        cin >> left >> right >> val;
        int ans = query(1, 1, n, left, right, val);
        cout << ans << "  **\n";
    }
}
int main()
{
    cout << "\nHello world!\n";
    int t = 1;
    // cin>>t;
    test(t)
    {
        solve();
    }
    return 0;
}

/*

10 2
1 4 3 5 6 4 3 2 4 1
1 5 4
7 10 4

*/