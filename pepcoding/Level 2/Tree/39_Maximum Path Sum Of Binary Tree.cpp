// 1. You are given a partially written function to solve.

// 2. You are required to complete the body of maxPathSum function. The function is expected to return Integer value depending upon node-to-node paths where path sum equals targetSum.

// 3. A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

// 4. The path sum of a path is the sum of the node's values in the path.

#include "makeTree.h"

int leafToLeafMaxSum = INT_MIN;
// {NodeToLeafMaxSum}
int maxPathSum(Node *root)
{
    if (!root)
        return INT_MIN;
    int left_nodeToLeafSum = maxPathSum(root->left);
    int right_nodeToLeafSum = maxPathSum(root->right);

    if (root->left && root->right)
        leafToLeafMaxSum = max(leafToLeafMaxSum, left_nodeToLeafSum + right_nodeToLeafSum + root->data);
    return max(left_nodeToLeafSum, right_nodeToLeafSum) + root->data;
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
    maxPathSum(root);
    cout << leafToLeafMaxSum;
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
