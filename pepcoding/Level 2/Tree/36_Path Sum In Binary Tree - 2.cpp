// 1. You are given a partially written function to solve.
// 2. You are required to complete the body of PathSum function. The function is expected to return all root-to-leaf paths where each path's sum equals targetSum.
// 3. Input and Output is managed for you.

#include "makeTree.h"
void pathSum(Node *root, int targetSum, vvi &res, vi &temp)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        if (targetSum - root->data == 0)
        {
            temp.pb(root->data);
            res.pb(temp);
            temp.pop_back();
        }
        return;
    }
    temp.pb(root->data);
    pathSum(root->left, targetSum - root->data, res, temp);
    pathSum(root->right, targetSum - root->data, res, temp);
    temp.pop_back();
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

    vvi res;
    vi temp;
    pathSum(root, 60, res, temp);
    for (int i = 0; i < res.size(); i++)
    {
        for (int node : res[i])
            cout << node << " ";
        cout << endl;
    }
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
