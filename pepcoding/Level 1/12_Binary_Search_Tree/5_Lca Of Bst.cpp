// 1. You are given a partially written BST class.
// 2. You are required to complete the body of lca function. "lca" function is expected to find the lowest commong ancestor of d1 and d2.
// 3. Input and Output is managed for you.

#include "../header.h"

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

Node *myBST(int *arr, int left, int right)
{
    if (left > right)
        return nullptr;
    int mid = (left + right) / 2;
    int data = arr[mid];
    Node *leftNode = myBST(arr, left, mid - 1);
    Node *rightNode = myBST(arr, mid + 1, right);
    Node *root = new Node(data, leftNode, rightNode);
    return root;
}
//?=====================================
//*=====================================

void display(Node *root)
{
    if (root)
    {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}

int LCA(Node *root, int val1, int val2)
{
    if (val1 < root->data && val2 < root->data)
        return LCA(root->left, val1, val2);
    else if (val1 > root->data && val2 > root->data)
        return LCA(root->right, val1, val2);
    else
        return root->data;
}

void solve()
{
    int arr[] = {12, 25, 30, 37, 40, 50, 60, 62, 70, 75, 87};
    Node *root = myBST(arr, 0, sizeof(arr) / sizeof(*arr) - 1);

    display(root);
    cout << "\n*****\n";
    cout << LCA(root, 62, 60);
    cout << endl;
}

int main()
{
    cout << "hello world!\n";
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

// 21
// 50 25 12 n n 37 30 n n n 75 62 60 n n 70 n n 87 n n
// 12
// 30