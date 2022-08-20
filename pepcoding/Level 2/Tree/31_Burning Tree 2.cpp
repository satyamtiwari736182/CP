// 1. Given a binary tree and target.
// 2. Find the minimum time required to burn the complete binary tree if the target is set on fire.
// 3. It is known that in 1 second all nodes connected to a given node get burned. That is, its left child, right child and parent.

#include "makeTree.h"

int maxTime = 0;
void burnTree(Node *root, Node *blockNode, int totalTime, vvi &ans)
{
    if (!root || root == blockNode)
        return;

    maxTime = max(maxTime, totalTime + 1);

    if (ans.size() <= totalTime)
        ans.resize(totalTime + 1);
    ans[totalTime].pb(root->data);

    burnTree(root->left, blockNode, totalTime + 1, ans);
    burnTree(root->right, blockNode, totalTime + 1, ans);
}

int burningTree_(Node *root, int fireNode, vvi &ans)
{
    if (!root)
        return -1;

    if (root->data == fireNode)
    {
        burnTree(root, nullptr, 0, ans);
        return 1;
    }

    int leftTime = burningTree_(root->left, fireNode, ans);
    if (leftTime != -1)
    {
        burnTree(root, root->left, leftTime, ans);
        return leftTime + 1;
    }

    int rightTime = burningTree_(root->right, fireNode, ans);
    if (rightTime != -1)
    {
        burnTree(root, root->right, rightTime, ans);
        return rightTime + 1;
    }

    return -1;
}

int burningTree(Node *root, int fireNode)
{
    if (!root)
        return 0;
    vvi ans;
    burningTree_(root, fireNode, ans);
    for (int i = 0; i < maxTime; i++)
    {
        cout << i << "-> ";
        for (int node : ans[i])
            cout << node << " ";
        cout << endl;
    }
    return maxTime;
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
    burningTree(root, 30);
    cout << maxTime;
    cout << "\n-------------------------------------\n";
    preOrder(root);
    cout << endl;
    inOrder(root);

    return 0;
}

// 9
// 50 25 75 12 37 62 87 30 70
/*
19
50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1
*/
