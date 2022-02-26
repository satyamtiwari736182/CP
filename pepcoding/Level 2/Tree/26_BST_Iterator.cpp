#include "makeTree.h"
class BSTIterator
{
    stack<Node *> st;
    void addAllLeft(Node *root)
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(Node *root)
    {
        addAllLeft(root);
    }

    bool hasNext()
    {
        return !st.empty();
    }
    int next()
    {
        Node *topNode = st.top();
        st.pop();
        addAllLeft(topNode->right);
        return topNode->data;
    }
};

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node *root = myTree(arr);

    BSTIterator itr(root);
    while (itr.hasNext())
        cout << itr.next() << " ";

    cout << "\n-------------------------------------\n";

    preOrder(root);
    cout << endl;
    inOrder(root);

    return 0;
}

// 9
// 50 25 75 12 37 62 87 30 70

// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1
