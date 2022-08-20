#include "../header.h"

class Node
{
public:
    int data;
    vector<Node *> children;
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
//*********************************************************
int idx = 0;
void serealizeTree(Node *root, string *asf)
{
    *asf += to_string(root->data) + " ";
    for (auto chld : root->children)
        serealizeTree(chld, asf);
    *asf += "null ";
}

Node *deSerealizeTree(string str)
{
    if (str.length() == 0)
        return nullptr;
    string type = "";
    vs arr;
    str_to_tok(str, ' ', arr, type);
    stack<Node *> stk;
    int val1 = 0;
    convert(arr[0], val1);
    Node *root = new Node();
    root->data = val1;
    stk.push(root);

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == "null")
            stk.pop();

        else
        {
            int val = 0;
            convert(arr[i], val);
            Node *node = new Node();
            node->data = val;

            stk.top()->children.pb(node);
            stk.push(node);
        }
    }

    return root;
}

int main()
{
    cout << "\nHello world!\n";
    int arr[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    //	int arr[] = {10 ,20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1};
    int n = sizeof(arr) / sizeof(*arr);

    Node *root = insert(arr, n);
    // display(root);
    string asf = "";
    serealizeTree(root, &asf);
    cout << asf;
    cout << "\n***************************\n";
    Node *node = deSerealizeTree(asf);
    display(node);

    return 0;
}

// 9
// 50 25 75 12 37 62 87 30 70

// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1

// 50 25 12 null null 37 30 null null null 75 62 null 70 null null 87 null null