#include "makeTree.h"

void leftView(Node *root)
{
    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        cout << que.front()->data << " ";
        while (size--)
        {
            Node *temp = que.front();
            if (temp->left)
                que.push(temp->left);
            if (temp->right)
                que.push(temp->right);
            que.pop();
        }
    }
    cout<<endl;
}


void rightView(Node *root)
{
    queue<Node *> que;
    que.push(root);
    while (!que.empty())
    {
        int size = que.size();
        cout << que.front()->data << " ";
        while (size--)
        {
            Node *temp = que.front();
            if (temp->right)
                que.push(temp->right);
            if (temp->left)
                que.push(temp->left);
            que.pop();
        }
    }
    cout<<endl;
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

    leftView(root);
    rightView(root);

    cout << "\n-------------------------------------\n";
    cout << endl;
    inOrder(root);

    return 0;
}

// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1
