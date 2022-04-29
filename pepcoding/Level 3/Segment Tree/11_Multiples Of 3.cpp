// There are N numbers(indexed from 1 to N) initially all are 0.
// You have to perform Q operations of two types:
// 1. 1 A B: increase all numbers in range from index A to B by 1.
// 2. 2 A B: count how many numbers in range from index A to B are divisible by 3.

#include "../header.h"

int *lazySeg, **segTree;
vi arr;

void shift(int *arr)
{
    int i0 = arr[0];
    arr[0] = arr[2];
    arr[2] = arr[1];
    arr[1] = i0;
}

void copy(int *ans, int *left, int *right)
{
    for (int i = 0; i <= 2; i++)
        ans[i] = left[i] + right[i];
}

void propagate(int node, int left, int right)
{
    lazySeg[node] = lazySeg[node] % 3;

    if (lazySeg[node] == 0)
        return;

    int temp = lazySeg[node];
    int leftNode = 2 * node, rightNode = 2 * node + 1;

    while (lazySeg[node]-- > 0)
        shift(segTree[node]);

    if (left != right)
    {
        lazySeg[leftNode] += temp;
        lazySeg[rightNode] += temp;
    }
}

void buildSegTree(int node, int left, int right)
{
    if (left == right)
        segTree[node][0] = 1;
    else
    {
        int mid = (left + right) / 2;
        int left_node = 2 * node;
        int right_node = 2 * node + 1;
        buildSegTree(left_node, left, mid);
        buildSegTree(right_node, mid + 1, right);
        copy(segTree[node], segTree[left_node], segTree[right_node]);
    }
}

void update(int node, int left, int right, int start, int end)
{
    propagate(node, left, right); // this propagation has to be at this place

    if (right < start || left > end)
        return;

    if (left == right)
        shift(segTree[node]);

    else if (start <= left && right <= end)
    {
        lazySeg[node]++;
        propagate(node, left, right);
    }

    else
    {
        int mid = (left + right) / 2;
        int left_node = 2 * node;
        int right_node = 2 * node + 1;

        update(left_node, left, mid, start, end);
        update(right_node, mid + 1, right, start, end);
        copy(segTree[node], segTree[left_node], segTree[right_node]);
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
        return segTree[node][0];

    // 3. Complete overlap of search-space with query range.
    else if (start <= left && right <= end)
        return segTree[node][0];

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

//!=========================================

int Update(int left, int right) // range update
{
    update(1, 1, arr.size() - 1, left, right);
}

int Query(int left, int right) // point update
{
    int ans = query(1, 1, arr.size() - 1, left, right);
    cout << ans << "  **\n";
}

//!=========================================
void solve()
{
    int n;
    cin >> n;
    arr.resize(n + 1);

    lazySeg = new int[4 * n];
    segTree = new int *[4 * n];

    memset(lazySeg, 0, sizeof(lazySeg));
    int i = 0, j = 0;
    REP(i, 0, 4 * n)
    segTree[i] = new int[3];

    i = 0;
    REP(i, 0, 4 * n)
    REP(j, 0, 3)
    segTree[i][j] = 0;

    buildSegTree(1, 1, arr.size());
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
            Update(left, right);
        }
        else if (type == 2)
        {
            int left, right;
            cin >> left >> right;
            Query(left, right);
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

// 4
// 7
// 2 1 4
// 1 2 3
// 1 2 4
// 2 1 1
// 1 1 4
// 2 4 4
// 2 1 4
