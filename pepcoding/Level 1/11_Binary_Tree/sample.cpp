// 1. You are given a partially written BinaryTree class.
// 2. You are required to complete the body of diameter1 function. The function is expected to return the number of edges between two nodes which are farthest from each other in terms of edges.
// 3. Input and Output is managed for you.

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
void inOrder(Node *root)
{
    if (root)
    {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
//?=====================================
//*=====================================
int getHeight(Node *root)
{
    if (root)
        return 1 + max(getHeight(root->left), getHeight(root->right));
    else
        return -1;
}

int diameter(Node *root)
{
    if (!root)
        return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    int diam = max(leftHeight + rightHeight + 2, max(leftDiameter, rightDiameter));
    return diam;
}
void rootToLeafPath(Node *root, int *path, int cnt)
{
    if (!root)
        return;
    path[cnt++] = (root->data);
    // (*cnt)++;
    if (!root->left && !root->right)
    {
        for (int i = 0; i < cnt; i++)
            cout << path[i] << " ";
        cout << endl;
    }
    if (root->left)
        rootToLeafPath(root->left, path, cnt);
    if (root->right)
        rootToLeafPath(root->right, path, cnt);

    // path.pop_back();
}
// void rootToLeafPath(Node *root, vi &path)
// {
//     if (!root)
//         return;
//     path.pb(root->data);
//     // (*cnt)++;
//     if (!root->left && !root->right)
//     {
//         for (int i : path)
//             cout << i << " ";
//         cout << endl;
//     }
//     if (root->left)
//         rootToLeafPath(root->left, path);
//     if (root->right)
//         rootToLeafPath(root->right, path);

//     path.pop_back();
// }

void sho(int (&arr)[3])
{
    arr[1] = 945;
    arr[2] = 405;
}
void solve()
{
    int arr[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, 40, -1, -1, 75, 62, 60, -1, -1, 70, -1, -1, 87, -1, -1};
    Node *root = myTree(arr);

    cout << diameter(root);
    cout << "\n*****\n";
    // inOrder(root);
    int cnt = 0, path[3];

    path[0] = 123;
    sho(path);
    for (int i = 0; i < 3; i++)
        cout << path[i] << " ";

    // vi path;
    // rootToLeafPath(root, path, cnt);
    int val = 70;
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