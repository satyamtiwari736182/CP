// 1. You are given a partially written BinaryTree class.
// 2. You are required to complete the body of createLeftCloneTree function. The function is expected to create a new node for every node equal in value to it and inserted between itself and it's left child. Check question video for clarity.
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
void inOrder(Node *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
//?=====================================
//*=====================================

Node *createLeftClonedTree(Node *root)
{
    if (!root)
        return nullptr;
    Node *leftNode = createLeftClonedTree(root->left);
    Node *rightNode = createLeftClonedTree(root->right);
    Node *node = new Node(root->data, leftNode, nullptr);
    root->left = node;
    root->right = rightNode;
    return root;
}

void solve()
{
    int arr[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, 40, -1, -1, 75, 62, 60, -1, -1, 70, -1, -1, 87, -1, -1};
    Node *root = myTree(arr);

    createLeftClonedTree(root);
    cout << "\n*****\n";
    inOrder(root);
    int val = 70;
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