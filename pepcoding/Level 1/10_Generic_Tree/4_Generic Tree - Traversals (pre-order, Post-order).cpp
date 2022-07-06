// 1. You are given a partially written GenericTree class.
// 2. You are required to complete the body of traversals function. The function is expected to visit every node. While traversing the function must print following content in different situations.
//    2.1. When the control reaches the node for the first time -> "Node Pre" node.data.
//    2.2. Before the control leaves for a child node from a node -> "Edge Pre"
//    node.data--child.data.
//    2.3. After the control comes back to a node from a child -> "Edge Post" node.data-
//    -child.data.
//     2.4. When the control is about to leave node, after the children have been visited
//     -> "Node Post" node.data.
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

void traversal(Node *root)
{
    // Euler's left,on the way deep in the recursion
    cout << "Node Pre " << root->data << endl;
    for (auto *chld : root->children)
    {
        // Edge-pre just invoking the child recursion
        cout << "Edge Pre " << root->data << "--" << chld->data << endl;
        traversal(chld);
        cout << "Edge Post " << chld->data << "--" << root->data << endl;
        // Edge-post just getting out of the child recursion
    }
    cout << "Node Post " << root->data << endl;
    // Euler's right,on the way out of the recursion.
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
    traversal(root);

    return 0;
}

// 12
// 10 20 -1 30 50 -1 60 -1 -1 40 -1 -1