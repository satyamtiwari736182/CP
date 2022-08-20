// 1. You are given a partially written function to solve.
// 2. You are required to complete the body of diameterOfBinaryTree function. The function is expected to return diameter of binary tree.
// 3. Input and Output is managed for you.

#include "makeTree.h"

int height(Node *root)
{
    return !root ? -1 : max(height(root->left), height(root->right)) + 1;
}

int diameter_I(Node *root)
{
    if (!root)
        return 0;

    int leftDiameter = diameter_I(root->left);
    int rightDiameter = diameter_I(root->right);

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int diameter_root_inc = leftHeight + rightHeight + 2;

    return max(max(leftDiameter, rightDiameter), diameter_root_inc);
}

//-----------------------------------------------------------------
//(diameter,height)
pi diameter_II(Node *root)
{
    if (!root)
        return {0, -1};
    pi leftRes = diameter_II(root->left);
    pi rightRes = diameter_II(root->right);
    pi myRes;
    myRes.fs = max(max(leftRes.fs, rightRes.fs), leftRes.se + rightRes.se + 2);
    myRes.se = max(leftRes.se, rightRes.se) + 1;
    return myRes;
}

int diameter__II(Node *root)
{
    return diameter_II(root).fs;
}

//-----------------------------------------------------------------

int diameter = 0;
int diameter_III(Node *root)
{
    if (!root)
        return -1;
    int leftHeight = diameter_III(root->left);
    int rightHeight = diameter_III(root->right);
    diameter = max(diameter, leftHeight + rightHeight + 2);
    return max(leftHeight, rightHeight) + 1;
}

//-----------------------------------------------------------------

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
    diameter_III(root);
    cout << diameter << endl;
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
