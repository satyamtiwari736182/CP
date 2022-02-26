#include "makeTree.h"

int lhld = 0, rhld = 0;

void width(Node *root, int hd)
{
    if (!root)
        return;
    lhld = min(lhld, hd);
    rhld = max(rhld, hd);
    if (root->left)
        width(root->left, hd - 1);
    if (root->right)
        width(root->right, hd + 1);
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

    width(root, 0);

    cout << "\n-------------------------------------\n"
         << lhld << " " << rhld << " " << (rhld - lhld + 1) << endl;
    preOrder(root);
    cout << endl;
    inOrder(root);

    return 0;
}

// 9
// 50 25 75 12 37 62 87 30 70

// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1
