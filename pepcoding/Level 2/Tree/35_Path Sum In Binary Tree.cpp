// 1. You are given a partially written function to solve.
// 2. You are required to complete the body of hasPathSum function. The function is expected to return boolean value depending upon root-to-leaf paths where path sum equals targetSum.
// 3. Input and Output is managed for you.

#include "makeTree.h"
bool hasPathSum(Node *root, int targetSum)
{
    if (!root)
        return false;
    if (!root->left && !root->right)
        return targetSum - root->data == 0;
    return hasPathSum(root->left, targetSum - root->data) || hasPathSum(root->right, targetSum - root->data);
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
    cout << "\n-------------------------------------\n";
    cout << hasPathSum(root, 87);
    cout << "\n-------------------------------------\n";
    preOrder(root);
    cout << endl;
    inOrder(root);

    return 0;
}

/*

19
50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1

*/
