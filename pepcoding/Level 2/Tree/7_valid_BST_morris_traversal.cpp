#include "makeTree.h"

Node *getRightMostNode(Node *leftNode, Node *curr)
{
    while (leftNode->right != nullptr && leftNode->right != curr)
        leftNode = leftNode->right;

    return leftNode;
}

bool inOrderMorrisTraversal(Node *root)
{
    Node *pre = nullptr;
    Node *curr = root;

    while (curr != nullptr)
    {
        Node *leftNode = curr->left;
        if (leftNode == nullptr)
        {
            //----------------------------------------
            // InOrder region
            // cout << curr->data << " ";
            if (pre == nullptr)
                pre = curr;
            else if (pre->data > curr->data)
                return false;

            //----------------------------------------
            curr = curr->right;
        }

        else
        {
            Node *rightMostNode = getRightMostNode(leftNode, curr);

            if (rightMostNode->right == nullptr) // checks previusly no one have created thread
            {
                rightMostNode->right = curr; // create thread
                curr = curr->left;
            }

            else // if thered already existed
            {
                rightMostNode->right = nullptr; // remove thread
                //------------------------------------------------------
                // InOrder region
                if (pre->data > curr->data)
                    return false;
                pre = curr;
                // cout << curr->data << " ";
                //-------------------------------------------------------
                curr = curr->right;
            }
        }
    }
    return true;
}
int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Node *root = myTree(arr);

    cout << inOrderMorrisTraversal(root);
    cout << endl;
    inOrder(root);

    return 0;
}

// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1

// 15
// 1 1 -1 1 1 -1 1 -1 -1 1 -1 -1 1 -1 -1
