// 1. Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.
// 2. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL.
// 3. The order of nodes in DLL must be the same as in Inorder for the given Binary Search Tree. The first node of Inorder traversal (leftmost node in BST) must be the head node of the DLL.

#include "makeTree.h"

//*******************************************
void IpostOrder(Node *root)
{
    stack<Node *> stk, postStack;
    stk.push(root);
    while (!stk.empty())
    {
        Node *node = stk.top();
        stk.pop();

        if (node->left)
            stk.push(node->left);

        if (node->right)
            stk.push(node->right);

        postStack.push(node);
    }

    while (!postStack.empty())
        cout << postStack.top()->data << " ", postStack.pop();
}

//*******************************************

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
    IpostOrder(root);

    cout << "\n-------------------------------------\n";
    // preOrder(root);
    // cout << endl;
    // inOrder(root);

    return 0;
}

// 9
// 50 25 75 12 37 62 87 30 70
/*
19
50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1
*/
