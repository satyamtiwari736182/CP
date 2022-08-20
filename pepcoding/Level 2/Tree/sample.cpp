
#include "makeTree.h"

Node *lca = nullptr;
bool LCA_DFS(Node *node, int p, int q)
{
    if (!node)
        return false;
    bool self_check = (node->data == p || node->data == q);

    bool left_res = LCA_DFS(node->left, p, q);
    if (lca)
        return true;

    bool right_res = LCA_DFS(node->right, p, q);
    if (lca)
        return true;

    if ((left_res && right_res) || (left_res && self_check) || (right_res && self_check))
        lca = node;

    return self_check || left_res || right_res;
}

//------------------------------------------------------------

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Node *root = myTree(arr);
    cout << "\n-------------------------------------\n";
    LCA_DFS(root, 70, 37);
    if (lca)
        cout << lca->data;
    else
        cout << "-1";
    // cout << (lca?lca->data:"-1");
    cout << "\n-------------------------------------\n";
    preOrder(root);
    cout << endl;
    inOrder(root);

    return 0;
}

/*
19
10 20 30 -1 -1 37 30 -1 -1 -1 25 15 -1 10 -1 -1 25 -1 -1

19
50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1

*/
