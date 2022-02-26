#include "makeTree.h"

int idx = 0;
Node *constructTree(vector<int> &preOrd, int lr, int rr)
{
    cout << lr << " " << preOrd[idx] << " " << rr << endl;
    if (idx >= preOrd.size() || preOrd[idx] < lr || preOrd[idx] > rr)
    {
        return nullptr;
    }
    Node *root = new Node(preOrd[idx++], nullptr, nullptr);
    root->left = constructTree(preOrd, lr, root->data);
    root->right = constructTree(preOrd, root->data, rr);
    return root;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
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
// 50 25 12 37 30 75 62 70 87

// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1
