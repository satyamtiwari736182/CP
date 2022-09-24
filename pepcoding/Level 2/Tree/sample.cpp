
#include "makeTree.h"

//------------------------------------------------------------

void Itaraversal(Node *root)
{
    stack<pair<Node *, int>> stk; //(Node,state)
    stk.push({root, 1});
    string pre = "", inord = "", post = "";
    while (!stk.empty())
    {
        Node *node = stk.top().fs;
        int state = stk.top().se;

        if (state == 1) // inord,state++,left
        {
            pre += to_string(node->data) + " ";
            stk.top().se++;
            if (node->left)
                stk.push({node->left, 1});
        }

        else if (state == 2) // inord, state++,right
        {
            inord += to_string(node->data) + " ";
            stk.top().se++;
            if (node->right)
                stk.push({node->right, 1});
        }

        else if (state == 3) // post,pop
        {
            post += to_string(node->data) + " ";
            stk.pop();
        }
    }

    cout << pre << "\n"
         << inord << "\n"
         << post;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Node *root = myTree(arr);
    cout << "\n-------------------------------------\n";
    Itaraversal(root);
    cout << "\n-------------------------------------\n";
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);

    return 0;
}

/*
19
10 20 30 -1 -1 37 30 -1 -1 -1 25 15 -1 10 -1 -1 25 -1 -1

19
50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1

*/
