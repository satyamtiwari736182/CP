#include <bits/stdc++.h>
using namespace std;
#define REP(a, b) for (int i = a; i <= b; i++)
#define REP2(i, a, b) for (i = a; i <= b; i++)
#define print(arr, l, r)         \
    for (int i = l; i <= r; i++) \
        cout << arr[i] << " ";
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define ll long long
#define fs first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define mod 1000000007
const int INF = 1e9 + 7;
const double PI = 3.141592653589793238;
const int M = 100, N = 100;

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

void preOrder(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
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

void postOrder(Node *root)
{
    if (root)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

void levelOrder(Node *root)
{
    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        while (size--)
        {
            auto temp = que.front();
            cout << temp->data << " ";
            if (temp->left)
                que.push(temp->left);
            if (temp->right)
                que.push(temp->right);
            que.pop();
        }
    }
}

bool find(Node *node, int data, string *psf)
{
    if (node)
    {
        *psf += " " + to_string(node->data);
        if (node->data == data)
            return true;
        else if (find(node->left, data, psf))
            return true;
        else if (find(node->right, data, psf))
            return true;
    }
    return false;
}

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

int solve(Node *node, int *sum, int *max, int *min)
{
    if (!node)
        return 0;

    *sum += node->data;

    if (*max < node->data)
        *max = node->data;

    if (*min > node->data)
        *min = node->data;

    return (1 + solve(node->left, sum, max, min) + solve(node->right, sum, max, min));
}

int main()
{
    int arr[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    Node *root = myTree(arr);

    //--------------------------------------------
    cout << endl;
    cout << "preOrder:   ";
    preOrder(root);
    cout << endl;
    cout << "inOrder:    ";
    inOrder(root);
    cout << endl;
    cout << "postOrder:  ";
    postOrder(root);
    cout << endl;
    cout << "levelOrder: ";
    levelOrder(root);
    cout << endl;
    //--------------------------------------------

    //--------------------------------------------
    int sum = 0, max = INT_MIN, min = INT_MAX;
    int size = solve(root, &sum, &max, &min);
    cout << endl
         << "size,sum,max,min: "
         << size << ", " << sum << ", " << max << ", " << min << endl;
    //--------------------------------------------
    string path = "";
    bool found = find(root, 12, &path);
    cout << endl
         << "hello! " << endl;
    cout << (found ? path : "not found");
    return 0;
}
 