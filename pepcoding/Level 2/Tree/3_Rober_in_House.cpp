#include "makeTree.h"

class Pairs
{
public:
    int robbed = 0, notrobbed = 0;
};

Pairs robber(Node *root)
{
    if (root == nullptr)
        return Pairs();
    Pairs left = robber(root->left);
    Pairs right = robber(root->right);
    Pairs myRes;
    myRes.robbed = root->data + left.notrobbed + right.notrobbed;
    myRes.notrobbed = left.robbed + right.robbed;
    return myRes;
}

int maxRoberingAmt(Node *root)
{
    Node *temp = root;
    Pairs res = robber(temp);
    cout << endl
         << res.robbed << "\t" << res.notrobbed << endl;
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
    maxRoberingAmt(root);
    return 0;
}

// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1
