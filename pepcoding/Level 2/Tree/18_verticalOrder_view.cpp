#include "makeTree.h"

class Pair1
{
public:
    int hd = 0;
    Node *node = nullptr;
    Pair1(Node *node, int hd) : node(node), hd(hd) {}
    Pair1() = default;
};

void verticalOrder(Node *root)
{
    queue<Pair1 *> que;
    que.push(new Pair1(root, 0));
    map<int, vector<int>> hashmap;
    int mxhd = 0, mnhd = 0;
    while (!que.empty())
    {
        int size = que.size();
        while (size--)
        {
            Pair1 *temp = que.front();
            que.pop();
            mxhd = max(mxhd, temp->hd);
            mnhd = min(mnhd, temp->hd);

            hashmap[temp->hd].push_back(temp->node->data);

            if (temp->node->left)
                que.push(new Pair1(temp->node->left, temp->hd - 1));
            if (temp->node->right)
                que.push(new Pair1(temp->node->right, temp->hd + 1));
        }
    }

        cout << "\n"
         << hashmap.size() << endl
         << mnhd << " " << mxhd << endl;
    for (int i = mnhd; i <= mxhd; i++)
        for (auto ele : hashmap[i])
            cout << ele << " ";
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

    verticalOrder(root);

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
