// 1. You are given a partially written BST class.
// 2. You are required to complete the body of add function. "add" function is expected to add a new node with given data to the tree and return the new root.
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

Node *addNode(Node *root, int val)
{
    if (!root)
        return new Node(val, nullptr, nullptr);

    if (val > root->data)
        root->right = addNode(root->right, val);
    else
        root->left = addNode(root->left, val);

    return root;
}

void solve()
{
    int arr[] = {12, 25, 30, 37, 40, 50, 60, 62, 70, 75, 87};
    Node *root = myBST(arr, 0, sizeof(arr) / sizeof(*arr) - 1);

    cout << "\n*****\n";
    addNode(root, 66);
    addNode(root, 45);
    display(root);
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

// 23
// 50 25 12 n n 37 30 n n 40 n n 75 62 60 n n 70 n n 87 n n
// 61