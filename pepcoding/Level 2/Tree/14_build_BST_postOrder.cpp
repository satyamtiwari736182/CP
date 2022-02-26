#include "makeTree.h"

int idx = 0;
Node *constructTree(vector<int> &postOrd, int lr, int rr)
{
    // cout << lr << " " << postOrd[idx] << " " << rr << endl;
    if (idx < 1 || postOrd[idx] < lr || postOrd[idx] > rr)
    {
        return nullptr;
    }
    Node *root = new Node(postOrd[--idx], nullptr, nullptr);
    root->left = constructTree(postOrd, lr, root->data);
    root->right = constructTree(postOrd, root->data, rr);
    return root;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    idx = n;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    Node *root = constructTree(arr, INT_MIN, INT_MAX);

    cout << "\n-------------------------------------\n"
         << (root == nullptr) << "\t" << idx << endl;
    preOrder(root);
    cout << endl;
    inOrder(root);

    return 0;
}

// 9
// 12 30 37 25 70 62 87 75 50

// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1
