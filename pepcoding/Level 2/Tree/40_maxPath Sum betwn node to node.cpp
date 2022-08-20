// 1. Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.
// 2. The path does not need to start or end at the root or a leaf,path can start from any where but it must go downwards


#include "makeTree.h"

// {NodeToNodeMaxSum,RootToNodeMaxSum}
pi maxPathSum(Node *root)
{
    pi myAns = mp(INT_MIN, INT_MIN);
    if (!root)
        return myAns;
    pi left_ans = maxPathSum(root->left);
    pi right_ans = maxPathSum(root->right);

    int RTN_maxSum = max(left_ans.se, right_ans.se) + root->data;
    int NTN_maxSum = max(max(left_ans.fs, right_ans.fs), max(left_ans.se + root->data + right_ans.se, max(root->data, RTN_maxSum)));

    myAns = {NTN_maxSum, max(RTN_maxSum, root->data)};
    return myAns;
}

int maxPathsum(Node *root)
{
    pi ans = maxPathSum(root);
    return max(ans.fs, ans.se);
}

//------------------------------------------------------------

// {RootToNodeMaxSum}
int NodeToNodeMaxSum = INT_MIN;
int maxPathSum_II(Node *root)
{
    if (!root)
        return 0;
    int left_RTRmaxSum = maxPathSum_II(root->left);
    int right_RTRmaxSum = maxPathSum_II(root->right);

    int RTN_maxSum = max(left_RTRmaxSum, right_RTRmaxSum) + root->data;
    NodeToNodeMaxSum = max(NodeToNodeMaxSum, max(left_RTRmaxSum + root->data + right_RTRmaxSum, max(root->data, RTN_maxSum)));

    return max(RTN_maxSum, root->data);
}

//------------------------------------------------------------

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
    maxPathSum_II(root);
    cout << NodeToNodeMaxSum;
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
