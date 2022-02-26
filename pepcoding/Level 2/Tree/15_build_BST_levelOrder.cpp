#include "makeTree.h"

class Pair1
{
public:
    int lr = INT_MIN, rr = INT_MAX;
    Node *par = nullptr;
    Pair1(Node *pare, int lb, int rb) : par(pare), lr(lb), rr(rb) {}
    Pair1() = default;
};

Node *constructTree(vector<int> &levelOrd)
{
    queue<Pair1 *> que;
    que.push(new Pair1());
    Node *root = nullptr;
    int idx = 0;
    while (!que.empty())
    {
        Pair1 *temp = que.front();
        que.pop();
        int ele = levelOrd[idx];
        if (ele < temp->lr || ele > temp->rr)
            continue;

        Node *node = new Node(ele, nullptr, nullptr);
        idx++;

        if (temp->par == nullptr)
            root = node;

        else
        {
            Node *par = temp->par;
            if (ele <= par->data)
                par->left = node;
            else
                par->right = node;
        }

        que.push(new Pair1(node, temp->lr, node->data));
        que.push(new Pair1(node, node->data, temp->rr));
    }

    return root;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;

    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    Node *root = constructTree(arr);

    cout << "\n-------------------------------------\n"
         << (root == nullptr) << "\t" << endl;
    preOrder(root);
    cout << endl;
    inOrder(root);

    return 0;
}

// 9
// 50 25 75 12 37 62 87 30 70

// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1
