// 1. You are given a partially written BinaryTree class.
// 2. You are given an element.
// 3. You are required to complete the body of find and nodeToRoot function. The functions are expected to
//     3.1. find -> return true or false depending on if the data is found in binary tree.
//     3.2. nodeToRoot -> returns the path from node (correspoding to data) to root in
//     form of an arraylist (root being the last element)
// 4. Input iand Output is managed for you.



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

bool findNode(Node *node, int data, string *psf)
{
    if (!node)
        return false;

    if (node->data == data)
    {
        *psf += " " + to_string(node->data);
        return true;
    }
    else if (findNode(node->left, data, psf))
    {
        *psf += " " + to_string(node->data);
        return true;
    }

    else if (findNode(node->right, data, psf))
    {
        *psf += " " + to_string(node->data);
        return true;
    }

    return false;
}

void solve()
{
    int arr[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    Node *root = myTree(arr);

    cout << "\n*****\n";
    int val = 70;
    string path = "";
    bool res = findNode(root, val, &path);
    cout << path << endl;
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
// 30