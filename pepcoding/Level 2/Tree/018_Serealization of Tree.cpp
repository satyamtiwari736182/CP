#include "makeTree.h"

string srealizeTree(Node *root)
{
    if (!root)
        return "null";
    string lans = srealizeTree(root->left);
    string rans = srealizeTree(root->right);
    return to_string(root->data) + " " + lans + " " + rans;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node *root = myTree(arr);
    cout << endl;
    cout << srealizeTree(root);

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
