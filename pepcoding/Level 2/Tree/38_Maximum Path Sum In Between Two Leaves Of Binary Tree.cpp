// 1. You are given a partially written function to solve.
// 2. You are required to complete the body of maxPathSum function. The function is expected to return Integer value depending upon maximum leaf-to-leaf paths sum.
// 3. Input and Output is managed for you.


#include "makeTree.h"

// {leafToLeafMaxSum,NodeToLeafMaxSum}
pi maxPathSum(Node *root)
{
    pi myAns = mp(INT_MIN, INT_MIN);
    if (!root)
        return myAns;
    if (!root->left && !root->right)
    {
        myAns.se += root->data;
        return myAns;
    }

    pi leftAns = maxPathSum(root->left);
    pi rightAns = maxPathSum(root->right);
    myAns.fs = max(leftAns.fs, rightAns.fs); // answer from => left-subtree and right-subtree

    if (root->left && root->right)
        myAns.fs = max(myAns.fs, leftAns.se + rightAns.se + root->data); // root making answer from => left-subtree, right-subtree and itself

    myAns.se = max(leftAns.se, rightAns.se) + root->data; // returning pathsum from node to leaf
    return myAns;
}

int maxPathsum(Node *root)
{
    pi ans = maxPathSum(root);
    return max(ans.fs, ans.se);
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
    cout << maxPathsum(root);
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
