// 1. Convert a sorted Doubly-Linked List to a Balanced Binary Search Tree in place.
// 2. The previous and next pointers in nodes are to be used as left and right pointers respectively in converted Binary Search Tree.
// 3. The tree must be constructed in-place (No new node should be allocated for tree conversion)

#include "makeTree.h"

Node *getMidNode(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast->right && fast->right->right)
        fast = fast->right->right, slow = slow->right;
    return slow;
}

// left:prev   next:right
Node *SortedDLLtoBST(Node *head)
{
    if (!head || !head->right)
        return head;
    Node *midNode = getMidNode(head);
    Node *prev = midNode->left, *forw = midNode->right;
    midNode->left = midNode->right = nullptr;
    if (prev)
        prev->right = nullptr;
    if (forw)
        forw->left = nullptr;

    Node *leftHead = prev ? head : nullptr;
    Node *rigtHead = forw;
    Node *root = midNode;

    root->left = SortedDLLtoBST(leftHead);
    root->right = SortedDLLtoBST(rigtHead);

    return root;
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

// 7
// 1 2 3 4 5 6 7
