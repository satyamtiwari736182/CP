// 1. You are given a partially written function to solve.
// 2. Given a binary tree root, a ZigZag path for a binary tree is defined as follow:
//     a. Choose any node in the binary tree and a direction (right or left).
//     b. If the current direction is right then move to the right child of the current node otherwise move to the left child.
//     c. Change the direction from right to left or right to left.
//     d. Repeat the second and third step until you can't move in the tree.

// 3.Zigzag length is defined in terms of edges. (A single node has a length of 0).
// 4. Return the longest ZigZag path contained in that tree.


#include "makeTree.h"

class Pairs
{
public:
    int forwardCnt = -1, backwardCnt = -1, maxCnt = -1;
};

Pairs maxPath(Node *root)
{
    if (root == nullptr)
        return Pairs();
    Pairs left = maxPath(root->left);
    Pairs right = maxPath(root->right);
    Pairs myRes;
    myRes.backwardCnt = 1 + left.forwardCnt;
    myRes.forwardCnt = 1 + right.backwardCnt;
    myRes.maxCnt = max(left.maxCnt, max(right.maxCnt, max(myRes.backwardCnt, myRes.forwardCnt)));
    return myRes;
}

int maxZigZagPath(Node *root)
{
    Node *temp = root;
    Pairs resCnt = maxPath(temp);
    cout << endl
         << resCnt.backwardCnt << "\t" << resCnt.maxCnt << "\t" << resCnt.forwardCnt << endl;
    return 0;
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
    preOrder(root);
    maxZigZagPath(root);
    return 0;
}

// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1

// 15
// 1 1 -1 1 1 -1 1 -1 -1 1 -1 -1 1 -1 -1


