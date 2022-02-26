#include "makeTree.h"

void kDown(Node *root, int k, Node *blockerNode, vector<Node *> &ans)
{
    if (root == nullptr || k < 0 || root == blockerNode)
        return;
    if (k == 0)
    {
        // cout << root->data << " ";
        ans.push_back(root);
        return;
    }
    kDown(root->left, k - 1, blockerNode, ans);
    kDown(root->right, k - 1, blockerNode, ans);
}

int kdistanceNode_targetNode(Node *root, int k, int target, vector<Node *> &ans)
{
    if (root == nullptr)
        return -1;
    if (root->data == target)
    {
        kDown(root, k, nullptr, ans);
        return 1;
    }

    int ld = kdistanceNode_targetNode(root->left, k, target, ans);
    if (ld != -1)
    {
        kDown(root, k - ld, root->left, ans);
        return ld + 1;
    }

    int rd = kdistanceNode_targetNode(root->right, k, target, ans);
    if (rd != -1)
    {
        kDown(root, k - rd, root->right, ans);
        return rd + 1;
    }

    return -1;
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
    vector<Node *> vec;
    // kDown(root, 2, nullptr, vec);
    kdistanceNode_targetNode(root, 6, 70, vec);
    for (auto node : vec)
        cout << node->data << " ";
    cout << "\n-------------------------------------\n";

    preOrder(root);
    cout << endl;
    inOrder(root);

    return 0;
}

// 9
// 50 25 75 12 37 62 87 30 70

// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1
