// 1. You are given a partially written BST class.
// 2. You are required to complete the body of remove function. "remove" function is expected to remove a new node with given data to the tree and return the new root.
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
int getMax(Node *root)
{
    int val = INT_MIN;
    while (root)
        val = max(val, root->data), root = root->right;
    return val;
}
Node *removeNode(Node *root, int val)
{
    if (!root)
        return nullptr;

    if (val > root->data)
        root->right = removeNode(root->right, val);
    else if (val < root->data)
        root->left = removeNode(root->left, val);

    else
    {
        if (root->left && root->right)
        {
            int maxVal = getMax(root->left);
            root->data = maxVal;
            removeNode(root->left, maxVal);
            return root;
        }
        else if (root->left)
            return root->left;
        else if (root->right)
            return root->right;
        else
            return nullptr;
    }

    return root;
}

void solve()
{
    int arr[] = {12, 25, 30, 37, 40, 50, 60, 62, 70, 75, 87};
    Node *root = myBST(arr, 0, sizeof(arr) / sizeof(*arr) - 1);

    cout << "\n*****\n";
    removeNode(root, 75);
    removeNode(root, 12);
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

// 15
// 50 25 12 n n 37 n n 75 62 n n 87 n n
// 62