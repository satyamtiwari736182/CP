// 1. Given the root of a binary tree, return the maximum width of the given tree.
// 2. The maximum width of a tree is the maximum width among all levels.
// 3. The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.

#include "makeTree.h"

int widthOfBinaryTree(Node *root)
{
    queue<pair<Node *, int>> que; // Node , idx
    int maxWidth = 0;
    que.push({root, 0});
    while (!que.empty())
    {
        int size = que.size();
        int leftIdx = que.front().se;
        int rightIdx = que.front().se;
        while (size-- > 0)
        {
            auto temp = que.front();
            que.pop();
            rightIdx = temp.se;
            if (temp.fs->left)
                que.push({temp.fs->left, 2 * temp.se + 1});
            if (temp.fs->right)
                que.push({temp.fs->right, 2 * temp.se + 2});
        }
        maxWidth = max(maxWidth, rightIdx - leftIdx + 1);
    }
    return maxWidth;
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
    cout << widthOfBinaryTree(root);
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
