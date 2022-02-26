#include "makeTree.h"

Node *constructTree(int *pstord, int *inord, int poi, int poj, int inoi, int inoj)
{
    if (inoi > inoj)
        return nullptr;
    int idx = inoi;
    while (inord[idx] != pstord[poj])
        idx++;
    int colse = idx - inoi; // count of left subtree elements.
    Node *root = new Node(pstord[poj], nullptr, nullptr);
    root->left = constructTree(pstord, inord, poi, poi + colse - 1, inoi, idx - 1);
    root->right = constructTree(pstord, inord, poi + colse, poj - 1, idx + 1, inoj);
    return root;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    int pstord[n], inord[n];
    for (int i = 0; i < n; i++)
        cin >> pstord[i];
    for (int i = 0; i < n; i++)
        cin >> inord[i];

    Node *root = constructTree(pstord, inord, 0, n - 1, 0, n - 1);

    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);

    return 0;
}

// 9
// 12 30 37 25 70 62 87 75 50
// 12 25 30 37 50 62 70 75 87

// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1

// 15
// 1 1 -1 1 1 -1 1 -1 -1 1 -1 -1 1 -1 -1
