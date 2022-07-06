// 1. You are given a partially written GenericTree class.
// 2. You are required to complete the body of max function. The function is expected to find the node with maximum value and return it.
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

int findMax(Node *root)
{
    //	if(!root) return 0;
    int mx = root->data;
    for (auto child : root->children)
    {
        int temp = findMax(child);
        if (mx < temp)
            mx = temp;
    }
    return mx;
}

int getSum(Node *root)
{
    //	if(!root) return 0;
    int sum = 0;
    for (auto child : root->children)
        sum += getSum(child);
    return sum + root->data;
}

int main()
{
    int arr[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    //	int arr[] = {10 ,20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1};
    int n = sizeof(arr) / sizeof(*arr);

    Node *root = insert(arr, n);
    display(root);

    //*===============================================
    int mx = findMax(root);
    int sum = getSum(root);
    cout << "\n**********\n";
    cout << "Max vlaue in tree = " << mx << endl;
    cout << "Sum of tree nodes= " << sum << endl;

    return 0;
}

// 12
// 10 20 -1 30 50 -1 60 -1 -1 40 -1 -1