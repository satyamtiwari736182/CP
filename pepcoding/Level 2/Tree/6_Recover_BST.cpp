#include "makeTree.h"

Node *pre = nullptr;
Node *a = nullptr;
Node *b = nullptr;

bool validBST(Node *root)
{
    if (root == nullptr)
        return true;
    if (!validBST(root->left))
        return false;

    if (pre != nullptr && pre->data > root->data)
    {
        if (!b)
        {
            a = pre;
            b = root;
        }
        else
            b = root;
    }
    pre = root;

    if (!validBST(root->right))
        return false;

    return true;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Node *root = myTree(arr);
    inOrder(root);
    cout << "\n"
         << validBST(root);
    cout << "\t" << a->data << "\t" << b->data << endl;
    swap(a->data, b->data);
    inOrder(root);

    return 0;
}

// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1

// 15
// 1 1 -1 1 1 -1 1 -1 -1 1 -1 -1 1 -1 -1
