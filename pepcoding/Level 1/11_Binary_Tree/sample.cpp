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

class BSTpair
{
public:
    int mini, maxi;
    bool isBST;
    BSTpair() : mini(INT_MAX), maxi(INT_MIN), isBST(true) {}
};

BSTpair *checkBST(Node *root)
{
    if (!root)
        return new BSTpair();
    BSTpair *leftpair = checkBST(root->left);
    BSTpair *rightpair = checkBST(root->right);

    BSTpair *nodePair = new BSTpair();
    nodePair->isBST = leftpair->isBST && rightpair->isBST && leftpair->maxi < root->data && rightpair->mini > root->data;
    nodePair->mini = min(root->data, min(leftpair->mini, rightpair->mini));
    nodePair->maxi = min(root->data, min(leftpair->maxi, rightpair->maxi));

    return nodePair;
}

void solve()
{
    int arr[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, 40, -1, -1, 75, 62, 60, -1, -1, 70, -1, -1, 87, -1, -1};
    Node *root = myTree(arr);
    // cout << tilt << endl;
    cout << checkBST(root)->isBST;
    cout << "\n*****\n";
    inOrder(root);
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