// 1. You are given a partially written GenericTree class.
// 2. You are required to complete the body of linearize function. The function is expected to create a linear tree i.e. every node will have a single child only. For details check the question video.
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
Node *getTail(Node *node)
{
    while (node->children.size() == 1)
        node = node->children[0];
    return node;
}

void linearizeTree(Node *root)
{
    for (auto chld : root->children)
        linearizeTree(chld);

    while (root->children.size() > 1)
    {
        Node *lstChld = root->children[root->children.size() - 1];
        root->children.erase(remove(all(root->children), lstChld));

        Node *secondLstChld = root->children[root->children.size() - 1];
        Node *secLastTail = getTail(secondLstChld);
        secLastTail->children.push_back(lstChld);
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
    linearizeTree(root);
    display(root);
    return 0;
}



// 24
// 10 20 50 -1 60 -1 -1 30 70 -1 80 110 -1 120 -1 -1 90 -1 -1 40 100 -1 -1 -1