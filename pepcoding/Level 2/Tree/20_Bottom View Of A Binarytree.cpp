// 1. Given a Binary Tree, print Bottom View of it.
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

class Pair1
{
public:
    Pair1(int hd, Node *node) : hd(hd), node(node) {}
    int hd;
    Node *node;
};

void verticalOrderTraversal(Node *root)
{
    int minMax[2] = {0};
    width(root, 0, minMax);
    queue<Pair1> que;
    int n = minMax[1] + abs(minMax[0]) + 1;
    vvi ans(n);
    que.push(Pair1(abs(minMax[0]), root));

    while (!que.empty())
    {
        int size = que.size();
        while (size-- > 0)
        {
            Pair1 temp = que.front();
            que.pop();
            // cout << temp.node->data << " " << temp.hd << ", ";
            ans[temp.hd].pb(temp.node->data);
            if (temp.node->left)
                que.push(Pair1(temp.hd - 1, temp.node->left));
            if (temp.node->right)
                que.push(Pair1(temp.hd + 1, temp.node->right));
        }
        // cout << endl;
    }

    // cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        // for (int node : ans[i])
        cout << ans[i][ans[i].size() - 1] << " ";
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
    verticalOrderTraversal(root);
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