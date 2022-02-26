#include "makeTree.h"

Node *pre = nullptr;

bool validBST(Node *root)
{
    if (root == nullptr)
        return true;
    if (!validBST(root->left))
        return false;
    //-----------------------------------------------------
    // InOrder region
    if (pre != nullptr && pre->data > root->data)
        return false;

    pre = root;
    //-----------------------------------------------------

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
    return 0;
}

// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1

// 15
// 1 1 -1 1 1 -1 1 -1 -1 1 -1 -1 1 -1 -1

/*
bool right = true, left = true;
    if (!root || root->left == nullptr && root->right == nullptr)
        return true;
    if (root->left)
        left = validBST(root->left);
    if (root->right)
        bool right = validBST(root->right);
    if (left == false || right == false)
        return false;
    if (root->data > root->left->data && root->data < root->right->data)
        return true;
    return false;
*/