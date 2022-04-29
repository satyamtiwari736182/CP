#include "../header.h"

vi arr;
class Node
{
public:
    Node *left, *right;
    int sum;
    Node(int sum)
    {
        this->sum = sum;
        left = nullptr;
        right = nullptr;
    }
    Node(Node *lft, Node *rht)
    {
        sum = lft->sum + rht->sum;
        left = lft;
        right = rht;
    }
};

Node *build(int left, int right)
{
    if (left == right)
        return new Node(0);
    else
    {
        int mid = (left + right) / 2;
        return new Node(build(left, mid), build(mid + 1, right));
    }
}

Node *update(Node *node, int left, int right, int pos, int val)
{
    if (left == right)
        return new Node(val);
    else
    {
        int mid = (left + right) / 2;
        if (left <= pos && pos <= mid)
            return new Node(update(node->left, left, mid, pos, val), node->right);
        else
            return new Node(node->left, update(node->right, mid + 1, right, pos, val));
    }
}

int query(Node *past, Node *pres, int left, int right, int k)
{
    if (left == right)
        return left;
    else
    {
        int mySegCount = pres->left->sum - past->left->sum;
        int mid = (left + right) / 2;
        if (k <= mySegCount)
            return query(past->left, pres->left, left, mid, k);
        else
            return query(past->right, pres->right, mid + 1, right, k - mySegCount);
    }
}

void solve()
{
    int n = 0, q, pos = 0, val = 0;

    cin >> n >> q;
    arr.resize(n);
    rarr(arr, 0, n);

    vector<vi> sorted(n);

    for (int i = 0; i < n; i++)
    {
        sorted[i].resize(2);
        sorted[i][0] = i;
        sorted[i][1] = arr[i];
    }

    sort(all(sorted), [&](auto a, auto b)
         { return a[1] < b[1]; });

    int idxInTree[n];
    for (int i = 0; i < n; i++)
        idxInTree[sorted[i][0]] = i;

    vector<Node *> states;
    states.pb(build(0, n - 1));

    for (int i = 0; i < n; i++)
    {
        Node *root = update(states[states.size() - 1], 0, n - 1, idxInTree[i], 1);
        states.pb(root);
    }

    test(q)
    {
        int left, right, k;
        cin >> left >> right >> k;
        left--;
        right--;

        int ans = query(states[left], states[right + 1], 0, n - 1, k);
        cout << sorted[ans][1] << "  **\n";
    }

    // states.pb(update(states[states.size() - 1], 0, n - 1, pos, val));
}

int main()
{
    cout << "\nHello world!\n";
    int t = 1;
    // cin >> t;
    test(t)
    {
        solve();
    }
    return 0;
}

// 7 3
// 1 5 2 6 3 7 4
// 2 5 3
// 4 4 1
// 1 7 3

//? 5 6 3