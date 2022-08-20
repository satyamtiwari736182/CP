// 1. Given a Binary Tree, print Diagonal Order of it anti-clock wise.
// 2. For more Information watch given video link below.

#include "makeTree.h"

void diagnolTraversal(Node *root)
{
    if (!root)
        return;
    queue<Node *> que;
    vvi ans;
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        vi diagnol;
        while (size-- > 0)
        {
            Node *node = que.front();
            que.pop();
            while (node)
            {
                diagnol.pb(node->data);
                if (node->right)
                    que.push(node->right);
                node = node->left;
            }
        }
        ans.pb(diagnol);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int node : ans[i])
            cout << node << " ";
        cout << endl;
    }
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
    diagnolTraversal(root);
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