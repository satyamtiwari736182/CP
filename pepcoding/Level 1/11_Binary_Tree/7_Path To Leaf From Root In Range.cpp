// 1. You are given a partially written BinaryTree class.
// 2. You are given a value lo and a value hi
// 3. You are required to complete the body of pathToLeafFromRoot function. The function is expected to print all paths from root to leaves which have sum of nodes in range from lo to hi (both inclusive). The elements in path should be separated by spaces. Each path should be in a separate line.
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

void findLeafToRootPath(Node *node, int sum, string psf, int low, int high)
{
    if (!node)
        return;
    if (node->left == nullptr && node->right == nullptr)
    {
        if (low <= sum && sum <= high)
        {
            psf = psf + " " + to_string(node->data);
            cout << psf << endl;
            return;
        }
    }
    findLeafToRootPath(node->left, sum + node->data, psf + " " + to_string(node->data), low, high);
    findLeafToRootPath(node->right, sum + node->data, psf + " " + to_string(node->data), low, high);
}

void solve()
{
    int arr[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, 40, -1, -1, 75, 62, 60, -1, -1, 70, -1, -1, 87, -1, -1};
    Node *root = myTree(arr);

    cout << "\n*****\n";
    int val = 70;
    findLeafToRootPath(root, 0, "", 40, 150);
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

// 23
// 50 25 12 n n 37 30 n n 40 n n 75 62 60 n n 70 n n 87 n n
// 150
// 250