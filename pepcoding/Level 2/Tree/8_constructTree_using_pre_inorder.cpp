// #include "makeTree.h"
#include <makeTree.h>

Node *constructTree(int *preord, int *inord, int pri, int prj, int inoi, int inoj)
{
    if (inoi > inoj)
        return nullptr;
    int idx = inoi;
    while (inord[idx] != preord[pri])
        idx++;
    int colse = idx - inoi; // count of left subtree elements.
    Node *root = new Node(preord[pri], nullptr, nullptr);
    root->left = constructTree(preord, inord, pri + 1, pri + colse, inoi, idx - 1);
    root->right = constructTree(preord, inord, pri + colse + 1, prj, idx + 1, inoj);
    return root;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    int preord[n], inord[n];
    for (int i = 0; i < n; i++)
        cin >> preord[i];
    for (int i = 0; i < n; i++)
        cin >> inord[i];

    Node *root = constructTree(preord, inord, 0, n - 1, 0, n - 1);

    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);

    return 0;
}
// 9
// 50 25 12 37 30 75 62 70 87
// 12 25 30 37 50 62 70 75 87

// 12 30 37 25 70 62 87 75 50

// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1

// 15
// 1 1 -1 1 1 -1 1 -1 -1 1 -1 -1 1 -1 -1
