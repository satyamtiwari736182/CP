#include "makeTree.h"

bool nodeToRootPath_I(Node *root, int data, vector<Node *> &nodeRootList)
{
    if (root == nullptr)
        return false;
    if (root->data == data)
    {
        nodeRootList.push_back(root);
        return true;
    }
    bool res = nodeToRootPath_I(root->left, data, nodeRootList) || nodeToRootPath_I(root->right, data, nodeRootList);
    if (res == true)
        nodeRootList.push_back(root);
    return res;
}

vector<Node *> nodeToRootPath_II(Node *root, int data)
{
    vector<Node *> nodeRootList;
    if (root == nullptr)
    {
        vector<Node *> nodeRootList;
        return nodeRootList;
    }
    else if (root->data == data)
    {
        vector<Node *> nodeRootList;
        nodeRootList.push_back(root);
        return nodeRootList;
    }

    else
    {
        vector<Node *> left = nodeToRootPath_II(root->left, data);
        if (left.size() != 0)
            nodeRootList = left;

        vector<Node *> right = nodeToRootPath_II(root->right, data);
        if (right.size() != 0)
            nodeRootList = right;
    }

    if (nodeRootList.size() != 0)
        nodeRootList.push_back(root);

    return nodeRootList;
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

    vector<Node *> vec = nodeToRootPath_II(root, 30);
    // cout << nodeToRootPath(root, 70, vec) << endl;
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
