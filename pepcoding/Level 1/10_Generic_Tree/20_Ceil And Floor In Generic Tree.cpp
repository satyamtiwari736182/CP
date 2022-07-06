// 1. You are given a partially written GenericTree class.
// 2. You are required to find the ceil and floor value of a given element. Use the "travel and change" strategy explained in the earlier video. The static properties - ceil and floor have been declared for you. You can declare more if you want. If the element is largest ceil will be largest integer value (32 bits), if element is smallest floor will be smallest integer value (32 bits). Watch the question video for clarity.
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
int cil = INT_MAX, flor = INT_MIN;
void findCeilFloor(Node *root, int val)
{
    if (root->data > val)
    {
        if (root->data < cil)
            cil = root->data;
    }

    if (root->data < val)
    {
        if (root->data > flor)
            flor = root->data;
    }

    for (auto chld : root->children)
        findCeilFloor(chld, val);
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
    findCeilFloor(root, 95);
    cout << flor << "\t" << cil << endl;

    return 0;
}

// 24
// 10 20 -50 -1 60 -1 -1 30 70 -1 -80 110 -1 -120 -1 -1 90 -1 -1 40 -100 -1 -1 -1
// 70