// 1. Given an integer array nums.
// 2. return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.


#include "../header.h"

class Node
{
public:
    Node *left, *right;
    Node() : left(nullptr), right(nullptr) {}
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

        bitIdx--;
    }
}

int query(Node *root, int findval)
{
    int bitIdx = 30;
    Node *curr = root;
    int ans = 0;

    while (bitIdx >= 0)
    {
        int mask = 1 << bitIdx;
        int bit = (mask & findval) > 0 ? 1 : 0;

        if (bit == 0)
        {
            if (curr->left != nullptr)
                curr = curr->left;
            else
                curr = curr->right, ans |= mask;
        }

        else
        {
            if (curr->right != nullptr)
                curr = curr->right, ans |= mask;
            else
                curr = curr->left;
        }
        bitIdx--;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    Node *root = new Node();

    for (int val : arr)
        insert(root, val);

    int mx_xor = 0;
    for (int val : arr)
    {
        int findval = INT_MAX ^ val;
        int res = query(root, findval);
        mx_xor = max(mx_xor, val ^ res);
    }

    cout << "\n"
         << mx_xor << endl;
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
6
3
10
5
25
2
8
*/