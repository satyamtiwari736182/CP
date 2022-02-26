#include "makeTree.h"

Node *constructTree(int *lvlord, int *inord, int lvli, int lvlj, int inoi, int inoj)
{
    if (inoi > inoj)
        return nullptr;
    int idx = inoi;
    while (inord[idx] != lvlord[lvli])
        idx++;

    Node *root = new Node(lvlord[lvli], nullptr, nullptr);

    set<int> hashset;
    for (int i = inoi; i < idx; i++)
        hashset.insert(inord[i]);

    int left_lvlord[idx - inoi] = {0};  // let index be as left_idx
    int right_lvlord[inoj - idx] = {0}; // let index be as right_idx
    int left_idx = 0, right_idx = 0;

    for (int i = 1; i < lvlj - lvli+1; i++)
    {
        int element = lvlord[i];
        if (hashset.size() != 0 && hashset.find(element) != hashset.end())
        {
            left_lvlord[left_idx++] = element;
            hashset.erase(element);
        }
        else
            right_lvlord[right_idx++] = element;
    }

    root->left = constructTree(left_lvlord, inord, 0, left_idx - 1, inoi, idx - 1);
    root->right = constructTree(right_lvlord, inord, 0, right_idx - 1, idx + 1, inoj);

    return root;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    int lvlord[n], inord[n];

    for (int i = 0; i < n; i++)
        cin >> inord[i];
    for (int i = 0; i < n; i++)
        cin >> lvlord[i];

    Node *root = constructTree(lvlord, inord, 0, n - 1, 0, n - 1);

    cout << "\n-------------------------------------\n";

    levelOrder(root);
    // preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);

    return 0;
}

// 9
// 12 25 30 37 50 62 70 75 87
// 50 25 75 12 37 62 87 30 70

// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1

// 15
// 1 1 -1 1 1 -1 1 -1 -1 1 -1 -1 1 -1 -1
