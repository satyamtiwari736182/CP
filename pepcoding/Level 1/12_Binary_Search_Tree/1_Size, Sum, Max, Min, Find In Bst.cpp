// 1. You are given a partially written BST class.
// 2. You are required to complete the body of size, sum, max, min and find function. The functions are expected to:
//     2.1. size - return the number of nodes in BST
//     2.2. sum - return the sum of nodes in BST
//     2.3. max - return the value of node with greatest value in BST
//     2.4. min - return the value of node with smallest value in BST
//     2.5. find - return true if there is node in the tree equal to "data"
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

int multiSolver(Node *node, int *sum, int *mx, int *min)
{
    if (!node)
        return -1;

    *sum += node->data;

    if (*mx < node->data)
        *mx = node->data;

    if (*min > node->data)
        *min = node->data;

    return (1 + max(multiSolver(node->left, sum, mx, min), multiSolver(node->right, sum, mx, min)));
}

int getSize(Node *root)
{
    if (root)
        return 1 + getSize(root->left) + getSize(root->right);
    else
        return 0;
}
int getSum(Node *root)
{
    if (root)
        return root->data + getSum(root->left) + getSum(root->right);
    else
        return 0;
}
int getHeight(Node *root)
{
    if (root)
        return 1 + max(getHeight(root->left), getHeight(root->right));
    else
        return -1;
}

int getMin(Node *root)
{
    int val = INT_MAX;
    while (root)
        val = min(val, root->data), root = root->left;
    return val;
}

int getMax(Node *root)
{
    int val = INT_MIN;
    while (root)
        val = max(val, root->data), root = root->right;
    return val;
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

void display(Node *root)
{
    if (root)
    {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}

void solve()
{
    int arr[] = {12, 25, 30, 37, 40, 50, 60, 62, 70, 75, 87};
    Node *root = myBST(arr, 0, sizeof(arr) / sizeof(*arr) - 1);

    cout << "\n*****\n";
    display(root);
    cout << endl;
    // int sum = 0, mx = 0, mn = INT_MAX;
    // int val = multiSolver(root, &sum, &mx, &mn);
    int val;
    cin >> val;
    cout << "Sum: " << getSum(root) << endl;
    cout << "Size: " << getSize(root) << endl;
    cout << "min: " << getMin(root) << endl;
    cout << "max: " << getMax(root) << endl;
    cout << "height: " << getHeight(root);
    cout << "search: " << findval(root, val);
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

// 19
// 50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n
// 70