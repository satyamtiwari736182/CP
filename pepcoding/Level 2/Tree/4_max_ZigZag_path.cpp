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


