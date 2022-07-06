// 1. You are given a partially written GenericTree class.
// 2. You are required to complete the body of IsSymmetric function. The function is expected to check if the tree is symmetric, if so return true otherwise return false. For knowing symmetricity think of face and hand. Face is symmetric while palm is not. Also, we are check only smmetricity of shape and not content. Check the question video for clarity.
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

bool isSymmetric(Node *root)
{
    return isMirror(root, root);
}

int main()
{
    int arr[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, 856, -1, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    //	int arr[] = {10 ,20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1};
    int n = sizeof(arr) / sizeof(*arr);

    Node *root = insert(arr, n);
    display(root);
    cout << "\n**************\n";
    //*===============================================

    cout << isSymmetric(root->children[1]);

    return 0;
}


// 20
// 10 20 50 -1 60 -1 -1 30 70 -1 80 -1 90 -1 -1 40 100 -1 110 -1 -1 -1