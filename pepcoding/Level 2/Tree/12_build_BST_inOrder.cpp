#include "makeTree.h"

Node *constructTree(int *inOrd, int i, int j)
{
    if (i > j)
        return nullptr;
    int mid = (i + j) / 2;
    Node *root = new Node(inOrd[mid], nullptr, nullptr);
    root->left = constructTree(inOrd, i, mid - 1);
    root->right = constructTree(inOrd, mid + 1, j);
    return root;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node *root = constructTree(arr, 0, n - 1);

    cout << "\n-------------------------------------\n";
    preOrder(root);
    cout << endl;
    inOrder(root);

    return 0;
}

// 9
// 12 25 30 37 50 62 70 75 87

// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1
