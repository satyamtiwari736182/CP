
// 1. You are given a partially written GenericTree class.
// 2. You are required to complete the body of lca function. The function is expected to return the lowest common ancestor of two data values that are passed to it.
// Please watch the question video to understand what lca is.
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
string psf = "";
vi findNodeToRootPath(Node *root, int val)
{

    if (root->data == val)
        return {root->data};
    for (auto chld : root->children)
    {
        vi pathUptoChild = findNodeToRootPath(chld, val);
        if (pathUptoChild.empty() == false)
        {
            pathUptoChild.pb(root->data);
            return pathUptoChild;
        }
    }
    return {};
}
int findLCA(Node *root, int val1, int val2)
{
    vi path1 = findNodeToRootPath(root, val1);
    vi path2 = findNodeToRootPath(root, val2);

    int i = path1.size() - 1, j = path2.size() - 1;

    while (i >= 0 && j >= 0 && path1[i] == path2[j])
        i--, j--;

    return path1[i + 1];
}
int main()
{
    int arr[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    //	int arr[] = {10 ,20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1};
    int n = sizeof(arr) / sizeof(*arr);

    Node *root = insert(arr, n);
    // display(root);
    cout << "\n**************\n";
    //*===============================================

    cout << findLCA(root, 90, 120) << endl;
    return 0;
}

// 24
// 10 20 50 -1 60 -1 -1 30 70 -1 80 110 -1 120 -1 -1 90 -1 -1 40 100 -1 -1 -1
// 120
// 80