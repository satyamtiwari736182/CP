#include "makeTree.h"

//! To get unique tree, the must be full or complete binary tree.

Node *constructTree(int *pstord, int *preord, int poi, int poj, int pri, int prj)
{
    if (pri > prj)
        return nullptr;
    Node *root = new Node(preord[pri], nullptr, nullptr);
    if (pri == prj)
        return root;
    int idx = poi;
    while (pstord[idx] != preord[pri + 1])
        idx++;
    int tnel = idx - poi + 1; // total number of elements.
    root->left = constructTree(pstord, preord, poi, idx, pri + 1, pri + tnel);
    root->right = constructTree(pstord, preord, idx + 1, poj - 1, pri + tnel + 1, prj);
    return root;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    int pstord[n], preord[n];

    for (int i = 0; i < n; i++)
        cin >> preord[i];

    for (int i = 0; i < n; i++)
        cin >> pstord[i];

    Node *root = constructTree(pstord, preord, 0, n - 1, 0, n - 1);
    cout << "\n-------------------------------\n";

    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    inOrder(root);

    return 0;
}

// 7
// 50 25 12 37 75 62 87
// 12 37 25 62 87 75 50

// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1

// 15
// 1 1 -1 1 1 -1 1 -1 -1 1 -1 -1 1 -1 -1
