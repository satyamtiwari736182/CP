// 1. You are given a partially written GenericTree class.
// 2. You are required to complete the body of areMirror function. The function is expected to check if the two trees passed to it are mirror images of each other in shape (data not to be checked, just the shape of tree).
// Note -> Watch the question video for clarity.
// 3. Input and Output is managed for you.

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

bool isMirror(Node *root1, Node *root2)
{
    if (root1->children.size() != root2->children.size())
        return false;

    for (int i = 0, j = root2->children.size() - 1; i < root1->children.size(); i++, j--)
        if (isMirror(root1->children[i], root2->children[j]) == false)
            return false;

    return true;
}

int main()
{
    int arr[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, 48};
    // int arr[] = {10, 20, 50, 456, -1, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, 48, 756};
    //	int arr[] = {10 ,20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1};
    int n = sizeof(arr) / sizeof(*arr);

    Node *root = insert(arr, n);
    display(root);
    cout << "\n**************\n";
    //*===============================================

    cout << isMirror(root->children[0], root->children[2]);

    return 0;
}

// 12
// 10 20 -1 30 50 -1 60 -1 -1 40 -1 -1
// 12
// 100 200 -1 300 500 -1 600 -1 -1 400 -1 -1