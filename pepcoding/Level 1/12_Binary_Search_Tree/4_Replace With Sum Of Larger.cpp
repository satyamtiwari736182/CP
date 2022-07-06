// 1. You are given a partially written BST class.
// 2. You are required to complete the body of rwsol function. "rwsol" function is expected to replace a node's value with sum of all nodes greater than it.
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

int sum = 0;
void replace_larger_sum(Node *root)
{
    if (!root)
        return;
    replace_larger_sum(root->right);
    int temp = root->data;
    root->data = sum;
    sum += temp;
    replace_larger_sum(root->left);
}

void solve()
{
    int arr[] = {12, 25, 30, 37, 40, 50, 60, 62, 70, 75, 87};
    Node *root = myBST(arr, 0, sizeof(arr) / sizeof(*arr) - 1);

    cout << "\n*****\n";
    replace_larger_sum(root);
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