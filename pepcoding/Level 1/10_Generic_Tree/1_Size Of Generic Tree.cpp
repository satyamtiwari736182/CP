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

int countNode(Node *root)
{
    //	if(!root) return 0;
    int sum = 1;
    for (auto child : root->children)
        sum += countNode(child);
    return sum;
}

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

int getHeight(Node *root)
{
    //	if(!root) return 1;

    int ht = -1;
    for (auto child : root->children)
    {
        int temp = getHeight(child);
        ht = max(ht, temp);
    }
    return ht + 1;
}

int getSum(Node *root)
{
    //	if(!root) return 0;
    int sum = 0;
    for (auto child : root->children)
    {
        sum += getSum(child);
    }
    return sum + root->data;
}

void preOrder(Node *root)
{
    //	cout<<root->data<<" ";
    queue<Node *> q;
    //	q.push(root);
    for (auto child : root->children)
    {
        cout << child->data << " ";
        q.push(child);
    }
    cout << endl;
    while (!q.empty())
    {
        preOrder(q.front());
        q.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int arr[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    //	int arr[] = {10 ,20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1};
    int n = sizeof(arr) / sizeof(*arr);

    Node *root = insert(arr, n);
    display(root);

    int size = countNode(root);
    int mx = findMax(root);
    int ht = getHeight(root);
    int sum = getSum(root);
    cout << endl;
    preOrder(root);
    cout << endl;

    cout << endl
         << "Size of tree = " << size << endl;
    cout << endl
         << "Max vlaue in tree = " << mx << endl;
    cout << endl
         << "Height of tree = " << ht << endl;
    cout << endl
         << "Sum of tree nodes= " << sum << endl;
    cout << "hello! " << n << endl;

    return 0;
}

// 12
// 10 20 -1 30 50 -1 60 -1 -1 40 -1 -1