#include "../header.h"

class Node
{
public:
    Node *left, *right;
    int count;
    Node() : left(nullptr), right(nullptr), count(0) {}
};

void insert(Node *root, int val)
{
    int bitIdx = 30;
    Node *curr = root;
    while (bitIdx >= 0)
    {
        int mask = 1 << bitIdx;
        int bit = (mask & val) > 0 ? 1 : 0;

        if (bit == 0)
        {
            if (curr->left == nullptr)
                curr->left = new Node();
            curr = curr->left;
        }
        else
        {
            if (curr->right == nullptr)
                curr->right = new Node();
            curr = curr->right;
        }
        curr->count++;

        bitIdx--;
    }
}

int getCount(Node *root)
{
    return (root == nullptr) ? 0 : root->count;
}

int query(Node *curr, int high, int val, int bitIdx)
{
    Node *root = curr;
    if (root == nullptr)
        return 0;

    if (bitIdx == -1)
        return getCount(root);

    int bitV = (val & (1 << bitIdx)) > 0 ? 1 : 0;
    int bitH = (high & (1 << bitIdx)) > 0 ? 1 : 0;

    if (bitV == 0)
    {
        if (bitH == 0)
            return query(root->left, high, val, bitIdx - 1);
        else
            return getCount(root->left) + query(root->right, high, val, bitIdx - 1);
    }

    else
    {
        if (bitH == 0)
            return query(root->right, high, val, bitIdx - 1);
        else
            getCount(root->right) + query(root->left, high, val, bitIdx - 1);
    }
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    Node *root = new Node();
    int cnt = 0, high, low;
    cin >> low >> high;

    for (int val : arr)
    {
        cnt += query(root, high, val, 30);
        cnt -= query(root, low - 1, val, 30);

        insert(root, val);
    }

    cout << "\n"
         << cnt << endl;
}

int main()
{
    cout << "\nHello world\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();

    return 0;
}

/*
4
1
4
2
7
3
5
*/