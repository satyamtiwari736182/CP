#include "../header.h"

struct Node
{
    vector<Node *> children;
    int data;
};

void display(Node *node)
{
    string str = to_string(node->data) + " -> ";

    for (auto child : node->children)
        str += to_string(child->data) + " ";

    cout << str << endl;

    for (auto child : node->children)
        display(child);
}

Node *insert(int *arr, int n)
{
    Node *root = new Node;
    root->data = arr[0];
    stack<Node *> st;
    st.push(root);

    for (int i = 1; i < n; i++)
    {
        struct Node *t = new Node;
        if (arr[i] == -1)
            st.pop();
        else
        {
            t->data = arr[i];
            if (st.size())
                st.top()->children.pb(t);
            st.push(t);
        }
    }
    return root;
}

//?=========================================================================
//*=========================================================================
int maxSum = INT_MIN, maxSumNode = INT_MIN;
int maxSubTreeSum(Node *root)
{
    for (auto chld : root->children)
    {
        int val = maxSubTreeSum(chld);
        maxSum = max(maxSum, val);
        maxSumNode += val;
    }
    return root->data + maxSumNode;
}
int main()
{
    int arr[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    //	int arr[] = {10 ,20, -1, 30, 50, -1, 60, -1, -1, 40, -1, -1};
    int n = sizeof(arr) / sizeof(*arr);

    Node *root = insert(arr, n);
    display(root);
    cout << "\n**************\n";
    //*===============================================
    maxSubTreeSum(root);
    cout << maxSum << "\t" << maxSumNode << endl;
    return 0;
}


  static int mSum = Integer.MIN_VALUE;
  static int mSumNode = Integer.MIN_VALUE;
  public static int nodeWithMaximumSubtreeSum(Node node) {
    int sum = node.data;

    for (Node child : node.children) {
      int cstSum = nodeWithMaximumSubtreeSum(child);
      sum += cstSum;
    }

    if (sum > mSum) {
      mSum = sum;
      mSumNode = node.data;
    }

    return sum;
  }