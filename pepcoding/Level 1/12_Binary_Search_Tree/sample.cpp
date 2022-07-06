
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
bool findval(Node *root, int val)
{
    if (root)
    {
        if (root->data == val)
            return true;
        else if (val > root->data)
            return findval(root->right, val);
        else
            return findval(root->left, val);
    }
    return false;
}

void travelAndPrint(Node *root, Node *node, int tar)
{
    if (!node)
        return;
    travelAndPrint(root, node->left, tar);
    int rem = tar - node->data;
    if (rem > node->data)
        if (findval(root, rem))
            cout << node->data << "," << rem << endl;
    travelAndPrint(root, node->right, tar);
}

void solve()
{
    int arr[] = {12, 25, 30, 37, 40, 50, 60, 62, 70, 75, 87};
    Node *root = myBST(arr, 0, sizeof(arr) / sizeof(*arr) - 1);

    display(root);
    cout << "\n*****\n";
    travelAndPrint(root, root, 100);
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