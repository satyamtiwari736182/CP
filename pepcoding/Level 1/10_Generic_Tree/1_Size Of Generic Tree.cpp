// 1. You are given a partially written GenericTree class.
// 2. You are required to complete the body of size function. The function is expected to count the number of nodes in the tree and return it.
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
    {
        str += to_string(child->data) + " ";
    }

    cout << str << endl;

    for (auto child : node->children)
    {
        display(child);
    }
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

int countNode(Node *root)
{
    //	if(!root) return 0;
    int sum = 1;
    for (auto child : root->children)
        sum += countNode(child);
    return sum;
}

int main()
{
    int arr[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    int n = sizeof(arr) / sizeof(*arr);
    Node *root = insert(arr, n);

    // display(root);

    //******************************
    int size = countNode(root);

    cout << "Size of tree = " << size << endl;

    return 0;
}

// 12
// 10 20 -1 30 50 -1 60 -1 -1 40 -1 -1
// ios_base::sync_with_stdio(false);
// cin.tie(nullptr);
// cout.tie(nullptr);