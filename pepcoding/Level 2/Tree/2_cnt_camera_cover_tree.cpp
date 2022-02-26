#include "makeTree.h"

int cnt = 0;
int minCamera(Node *root)
{
    /*
     * -1 => Camera needed
     * 0  => your are camera
     * 1  => you are covered
     */
    if (root == nullptr)
        return 1;
    int leftAns = minCamera(root->left);
    int rightAns = minCamera(root->right);
    if (leftAns == -1 || rightAns == -1)
    {
        cnt++;
        return 0;
    }
    if (leftAns == 0 || rightAns == 0)
        return 1;
    return -1;
}
int countCamera(Node *root)
{
    if (minCamera(root) == -1)
        cnt++;
    return cnt;
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
    preOrder(root);
    cout << endl
         << "#Camera: " << countCamera(root) << "\t"
         << cnt << endl;
    return 0;
}

// 19
// 50 25 12 -1 -1 37 30 -1 -1 -1 75 62 -1 70 -1 -1 87 -1 -1