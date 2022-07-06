// 1. You are given a partially written GenericTree class.
// 2. You are required to complete the body of levelorderLineWiseZZ function. The function is expected to visit every node in "levelorder fashion" but in a zig-zag manner i.e. 1st level should be visited from left to right, 2nd level should be visited from right to left and so on. All nodes on same level should be separated by a space. Different levels should be on separate lines. Please check the question video for more details.
// 3. Input is managed for you.

#include "../header.h"

struct Node
{
    vector<Node *> children;
    int data;
};

void display(Node *node)
{
    string str = to_string(node->data) + " -> ";

    for (auto child : node->children)
        str += to_string(child->data) + " ";

    cout << str << endl;

    for (auto child : node->children)
        display(child);
}

Node *insert(int *arr, int n)
{
    Node *root = new Node;
    root->data = arr[0];
    stack<Node *> st;
    st.push(root);

    for (int i = 1; i < n; i++)
    {
        struct Node *t = new Node;
        if (arr[i] == -1)
            st.pop();
        else
        {
            t->data = arr[i];
            if (st.size())
                st.top()->children.pb(t);
            st.push(t);
        }
    }
    return root;
}

//?=========================================================================
//*=========================================================================

void levelOrderLinewiseZZ(Node *root)
{
    stack<Node *> mainStk, secStk;

    mainStk.push(root);
    int level = 1; // 0 or 1
    while (!mainStk.empty())
    {
        Node *node = mainStk.top();
        mainStk.pop();
        cout << node->data << " ";

        if (level % 2 == 0)
            for (auto chld : node->children)
                secStk.push(chld);
        else
            for (int i = node->children.size() - 1; i >= 0; i--)
                secStk.push(node->children[i]);

        if (mainStk.empty())
        {
            mainStk = secStk;
            stack<Node *> temp;
            secStk = temp;
            level++;
            cout << endl;
        }
    }
}

int main()
{
    int arr[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    //	int arr[] = {10 ,20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1};
    int n = sizeof(arr) / sizeof(*arr);

    Node *root = insert(arr, n);
    display(root);
    cout << "\n**************\n";
    //*===============================================
    levelOrderLinewiseZZ(root);

    return 0;
}

// 24
// 10 20 50 -1 60 -1 -1 30 70 -1 80 110 -1 120 -1 -1 90 -1 -1 40 100 -1 -1 -1