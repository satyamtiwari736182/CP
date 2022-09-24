// 1. You are given a partially written BinaryTree class.
// 2. You are required to complete the body of iterativePrePostInTraversal function. The function is expected to print pre order, in order and post order of the tree in separate lines (first pre, then in and finally post order). All elements in an order must be separated by a space.
// 3. Input is managed for you.

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

void IpostOrder_II(Node *root)
{
    stack<Node *> stk, postStack;
    stk.push(root);
    while (!stk.empty())
    {
        Node *node = stk.top();
        stk.pop();
        if (node->left)
            stk.push(node->left);
        if (node->right)
            stk.push(node->right);
        postStack.push(node);
    }

    while (!postStack.empty())
        cout << postStack.top()->data << " ", postStack.pop();
}
//?=====================================
//*=====================================
void Itaraversal(Node *root)
{
    stack<pair<Node *, int>> stk; //(Node,state)
    stk.push({root, 1});
    string pre = "", inord = "", post = "";
    while (!stk.empty())
    {
        Node *node = stk.top().fs;
        int state = stk.top().se;

        if (state == 1) // inord,state++,left
        {
            pre += to_string(node->data) + " ";
            stk.top().se++;
            if (node->left)
                stk.push({node->left, 1});
        }

        else if (state == 2) // inord, state++,right
        {
            inord += to_string(node->data) + " ";
            stk.top().se++;
            if (node->right)
                stk.push({node->right, 1});
        }

        else if (state == 3) // post,pop
        {
            post += to_string(node->data) + " ";
            stk.pop();
        }
    }

    cout << pre << "\n"
         << inord << "\n"
         << post;
}

//*=======================================================

void addAllLeftNodes(Node *node, stack<Node *> &stk)
{
    while (node)
        stk.push(node), node = node->left;
}

void IpreOrder(Node *root)
{
    stack<Node *> stk;
    stk.push(root);
    while (!stk.empty())
    {
        Node *node = stk.top();
        stk.pop();
        while (node)
        {
            cout << node->data << " ";
            stk.push(node->right);
            node = node->left;
        }
    }
}

void IinOrder(Node *root)
{
    stack<Node *> stk;

    addAllLeftNodes(root, stk);
    while (!stk.empty())
    {
        Node *curr = stk.top();
        stk.pop();
        cout << curr->data << " ";
        addAllLeftNodes(curr->right, stk);
    }
}

void IpostOrder(Node *root)
{
    stack<Node *> stk;
    Node *node = root;
    while (!stk.empty() || node)
    {
        if (node)
            stk.push(node), node = node->left;
        else
        {
            Node *temp = stk.top()->right;
            if (temp)
                node = temp;
            else
            {
                temp = stk.top();
                stk.pop();
                cout << temp->data << " ";

                while (!stk.empty() && temp == stk.top()->right)
                {
                    temp = stk.top();
                    stk.pop();
                    cout << temp->data << " ";
                }
            }
        }
    }
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
    IpreOrder(root);
    cout << endl;
    IinOrder(root);
    cout << endl;
    IpostOrder(root);
    cout << "\n-------------------------------------\n";
    // preOrder(root);
    // cout << endl;
    // inOrder(root);
    // cout << endl;
    // postOrder(root);

    return 0;
}

/*
19
10 20 30 -1 -1 37 30 -1 -1 -1 25 15 -1 10 -1 -1 25 -1 -1

19
50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1

*/
