#include "makeTree.h"

void allSingleChild_node(Node *root)
// It just prints
{
    if (root == nullptr || root->left == nullptr && root->right == nullptr)
        return;
    if (root->left == nullptr || root->right == nullptr)
        cout << root->data << " ";
    allSingleChild_node(root->left);
    allSingleChild_node(root->right);
}

vector<Node *> allSingleChild_node_II(Node *root)
// It returns the list;
{
    vector<Node *> singleNodeList;
    if (root == nullptr || root->left == nullptr && root->right == nullptr)
        return singleNodeList;
    if (root->left == nullptr || root->right == nullptr)
    {
        singleNodeList.push_back(root);
        return singleNodeList;
    }
    vector<Node *> leftList = allSingleChild_node_II(root->left);
    vector<Node *> rightList = allSingleChild_node_II(root->right);

    singleNodeList = leftList;

    for (auto node : rightList)
        singleNodeList.push_back(node);

    return singleNodeList;
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
    // allSingleChild_node(root);
    vector<Node *> vec = allSingleChild_node_II(root);
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
