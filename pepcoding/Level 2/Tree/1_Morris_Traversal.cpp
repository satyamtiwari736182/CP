#include "makeTree.h"

Node *getRightMostNode(Node *leftNode, Node *curr)
{
    while (leftNode->right != nullptr && leftNode->right != curr)
        leftNode = leftNode->right;

    return leftNode;
}

void inOrderMorrisTraversal(Node *root)
{
    Node *curr = root;
    while (curr != nullptr)
    {
        Node *leftNode = curr->left;
        if (leftNode == nullptr)
        {
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            Node *rightMostNode = getRightMostNode(leftNode, curr);
            if (rightMostNode->right == nullptr)
            {
                rightMostNode->right = curr; // create thread
                curr = curr->left;
            }
            else
            {
                rightMostNode->right = nullptr; // remove thread
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}
void preOrderMorrisTraversal(Node *root)
{
    Node *curr = root;
    while (curr != nullptr)
    {
        Node *leftNode = curr->left;
        if (leftNode == nullptr)
        {
            //---------------------------------------------
            // PreOrder Region
            cout << curr->data << " ";
            //---------------------------------------------
            curr = curr->right;
        }
        else
        {
            Node *rightMostNode = getRightMostNode(leftNode, curr);
            if (rightMostNode->right == nullptr)
            {
                rightMostNode->right = curr; // create thread
                //----------------------------------------------
                // PreOrder Region
                cout << curr->data << " ";
                //----------------------------------------------
                curr = curr->left;
            }
            else
            {
                rightMostNode->right = nullptr; // remove thread
                curr = curr->right;
            }
        }
    }
}

void postOrderMorrisTraversal(Node *root)
/*Not required*/
{
    Node *curr = new Node(0, root, nullptr);
    Node *first, *middle, *last;
    while (curr != nullptr)
    {
        Node *leftNode = curr->left;
        if (leftNode == nullptr)
            curr = curr->right;

        else
        {
            Node *rightMostNode = getRightMostNode(leftNode, curr);
            if (rightMostNode->right == nullptr)
            {
                // rightMostNode found for first time
                // modify the tree
                rightMostNode->right = curr; // create thread
                curr = curr->left;
            }
            else
            {
                // rightMostNode found second time
                // reverse the right references in chain from rightMostNode to curr
                first = curr;
                middle = curr->left;
                while (middle != curr)
                {
                    last = middle->right;
                    middle->right = first;
                    first = middle;
                    middle = last;
                }

                // visit the nodes from rightMostNode to curr
                // again reverse the right references from rightMostNode to curr
                first = curr;
                middle = rightMostNode;
                while (middle != curr)
                {
                    cout << middle->data << " ";
                    last = middle->right;
                    middle->right = first;
                    first = middle;
                    middle = last;
                }

                rightMostNode->right = nullptr; // remove thread
                curr = curr->right;
            }
        }
    }
}

int main()
{
    int arr[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    Node *root = myTree(arr);
    cout << endl
         << "InOrder: ";
    // inOrderMorrisTraversal(root);
    postOrderMorrisTraversal(root);

    //--------------------------------------------
    cout << endl;
    cout << "preOrder:";
    inOrder(root);
    return 0;
}