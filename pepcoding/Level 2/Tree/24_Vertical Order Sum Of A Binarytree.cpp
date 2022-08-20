// 1. Given a Binary Tree, print Vertical Order Sum of it. 
// 2. For more Information watch given video link below.

#include "makeTree.h"

void width(Node *root, int hd, int *ans)
{
    if (!root)
        return;
    ans[0] = min(ans[0], hd);
    ans[1] = max(ans[1], hd);
    if (root->left)
        width(root->left, hd - 1, ans);
    if (root->right)
        width(root->right, hd + 1, ans);
}

void verticalOrderSum(Node *root, int hd, vi &ans)
{
    if (!root)
        return;
    ans[hd] += root->data;
    verticalOrderSum(root->left, hd - 1, ans);
    verticalOrderSum(root->right, hd + 1, ans);
}
void verticalOrderSum(Node *root)
{
    if (!root)
        return;
    int minMax[2] = {0};
    width(root, 0, minMax);
    vi vSum(minMax[1] - minMax[0] + 1);
    verticalOrderSum(root, abs(minMax[0]), vSum);
    for (int val : vSum)
        cout << val << " ";
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
    verticalOrderSum(root);
    cout << "\n-------------------------------------\n";
    preOrder(root);
    cout << endl;
    inOrder(root);

    return 0;
}
/*
9
50 25 75 12 37 62 87 30 70

19
50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1

*/