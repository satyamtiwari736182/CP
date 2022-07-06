// 1. You are given a partially written BinaryTree class.
// 2. You are required to complete the body of size, sum, max and height function. The functions are expected to
//     2.1. size - return the number of nodes in BinaryTree
//     2.2. sum - return the sum of nodes in BinaryTree
//     2.3. max - return the highest node in BinaryTree
//     2.4. height - return the height of tree in terms of edges
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

class Pair
{
public:
    int state;
    Node *node;
    Pair(Node *node, int state)
    {
        this->state = state;
        this->node = node;
    }
};

Node *myTree(int *arr)
{
    stack<Pair *> st;
    Node *root = new Node(arr[0], nullptr, nullptr);
    st.push(new Pair(root, 1));

    int i = 1;

    while (st.size())
    {
        Pair *temp = st.top();
        if (temp->state == 1)
        {
            if (arr[i] != -1)
            {
                Node *node = new Node(arr[i], nullptr, nullptr);
                temp->node->left = node;
                st.push(new Pair(node, 1));
            }

            temp->state++;
            i++;
        }
        else if (temp->state == 2)
        {
            if (arr[i] != -1)
            {
                Node *node = new Node(arr[i], nullptr, nullptr);
                temp->node->right = node;
                st.push(new Pair(node, 1));
            }
            temp->state++;
            i++;
        }
        else
            st.pop();
    }
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

void solve()
{
    int arr[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    Node *root = myTree(arr);

    cout << "\n*****\n";
    int sum = 0, mx = 0, mn = INT_MAX;
    int val = multiSolver(root, &sum, &mx, &mn);

    cout << "Sum: " << sum << endl;
    cout << "max: " << mx << endl;
    cout << "min: " << mn << endl;
    cout << "height: " << val;
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