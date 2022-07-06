// 1. You are given a partially written BinaryTree class.
// 2. You are given a value data and a value k.
// 3. You are required to complete the body of printKNodesFar function. The function is expected to print all nodes which are k distance away in any direction from node with value equal to data.
// 4. Input is managed for you.

#include "../header.h"

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class Pair
{
public:
    int state;
    Node *node;
    Pair(Node *node, int state)
    {
        this->state = state;
        this->node = node;
    }
};

Node *myTree(int *arr)
{
    stack<Pair *> st;
    Node *root = new Node(arr[0], nullptr, nullptr);
    st.push(new Pair(root, 1));

    int i = 1;

    while (st.size())
    {
        Pair *temp = st.top();
        if (temp->state == 1)
        {
            if (arr[i] != -1)
            {
                Node *node = new Node(arr[i], nullptr, nullptr);
                temp->node->left = node;
                st.push(new Pair(node, 1));
            }

            temp->state++;
            i++;
        }
        else if (temp->state == 2)
        {
            if (arr[i] != -1)
            {
                Node *node = new Node(arr[i], nullptr, nullptr);
                temp->node->right = node;
                st.push(new Pair(node, 1));
            }
            temp->state++;
            i++;
        }
        else
            st.pop();
    }
    return root;
}

//?=====================================
//*=====================================
void printKdown(Node *root, int k, Node *blck)
{
    if (!root || k < 0 || root == blck)
        return;
    if (k == 0)
        cout << root->data << " ";
    printKdown(root->left, k - 1, blck);
    printKdown(root->right, k - 1, blck);
}

bool findNodeToRootPath(Node *node, int data, vector<Node *> &path)
{
    if (!node)
        return false;

    if (node->data == data)
    {
        path.pb(node);
        return true;
    }
    else if (findNodeToRootPath(node->left, data, path))
    {
        path.pb(node);
        return true;
    }

    else if (findNodeToRootPath(node->right, data, path))
    {
        path.pb(node);
        return true;
    }

    return false;
}

void printKDistanceAwy(Node *root, int val, int k)
{
    vector<Node *> nodeRootPath;
    findNodeToRootPath(root, val, nodeRootPath);
    for (int i = 0; i < nodeRootPath.size(); i++)
        printKdown(nodeRootPath[i], k - i, (i == 0 ? nullptr : nodeRootPath[i - 1]));
}

void solve()
{
    int arr[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, 40, -1, -1, 75, 62, 60, -1, -1, 70, -1, -1, 87, -1, -1};
    Node *root = myTree(arr);

    cout << "\n*****\n";
    int val = 70;
    printKDistanceAwy(root, 75, 3);
}

int main()
{
    cout << "hello world!\n";
    int t = 1;
    // cin>>t;
    test(t)
        solve();
    return 0;
}

// 19
// 50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n
// 37
// 2