// 1. Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.
// 2. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL.
// 3. The order of nodes in DLL must be the same as in Inorder for the given Binary Search Tree. The first node of Inorder traversal (leftmost node in BST) must be the head node of the DLL.

#include "makeTree.h"

void addAllLeftNodes(Node *node, stack<Node *> &stk)
{
    while (node)
        stk.push(node), node = node->left;
}

Node *BSTtoDLL(Node *root)
{
    stack<Node *> stk;
    Node *dummy = new Node(-1, nullptr, nullptr);
    Node *prev = dummy;

    addAllLeftNodes(root, stk);
    while (!stk.empty())
    {
        Node *curr = stk.top();
        // debug(curr->data);
        stk.pop();
        prev->right = curr;
        curr->left = prev;
        prev = curr;
        addAllLeftNodes(curr->right, stk);
    }
    Node *head = dummy->right;
    dummy->right = head->left = nullptr;

    // head->left = prev, prev->right = head;
    return head;
}


//*******************************************
//! Method II
Node *prev = nullptr;
void BSTtoDLL_(Node *curr)
{
    if (!curr)
        return;
    BSTtoDLL_(curr->left);
    ::prev->right = curr;
    curr->left = ::prev;
    ::prev = curr;
    BSTtoDLL_(curr->right);
}

Node *BSTtoDLL_II(Node *root)
{
    Node *dummy = new Node(-1, nullptr, nullptr);
    ::prev = dummy;
    BSTtoDLL_(root);
    Node *head = dummy->right;
    dummy->right = head->left = nullptr;
    // head->left = prev, prev->right = head;
    return head;
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
    Node *head = BSTtoDLL(root);
    Node *temp = head;
    while (temp->right)
        cout << temp->data << " ", temp = temp->right;
    cout << temp->data << endl;
    while (temp)
        cout << temp->data << " ", temp = temp->left;

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
