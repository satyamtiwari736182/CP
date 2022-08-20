#include "makeTree.h"

int idx = 0;

Node *deSerealizeTree(vs &arr)
{
    if (idx >= arr.size() || arr[idx] == "null")
    {
        idx++;
        return nullptr;
    }

    int data = 0;
    convert(arr[idx++], data);

    Node *root = new Node(data, nullptr, nullptr);
    root->left = deSerealizeTree(arr);
    root->right = deSerealizeTree(arr);
    return root;
}

int main()
{
    cout << "\nHello world!\n";
    string str, type;
    fflush(stdin);
    getline(cin, str);

    vs arr;
    str_to_tok(str, ' ', arr, type);
    parr(arr, arr.size());
    Node *root = deSerealizeTree(arr);
    cout << idx << endl;
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

// 50 25 12 null null 37 30 null null null 75 62 null 70 null null 87 null null