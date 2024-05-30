# Binary Tree
    [0] pre-order, post-order, in-order, level-order traversal.
    [1] Building trees.
    [3] Node to root Path
    [4] Count min camera required to cover the tree
## All nodes at k-distance
```cpp
void kDown(Node *root, int k, Node *blockerNode, vector<Node *> &ans)
{
    if (root == nullptr || k < 0 || root == blockerNode)
        return;
    if (k == 0)
    {
        ans.push_back(root);
        return;
    }
    kDown(root->left, k - 1, blockerNode, ans);
    kDown(root->right, k - 1, blockerNode, ans);
}

int kdistanceNode_targetNode(Node *root, int k, int target, vector<Node *> &ans)
{
    if (root == nullptr)
        return -1;
    if (root->data == target)
    {
        kDown(root, k, nullptr, ans);
        return 1;
    }

    int ld = kdistanceNode_targetNode(root->left, k, target, ans);
    if (ld != -1)
    {
        kDown(root, k - ld, root->left, ans);
        return ld + 1;
    }

    int rd = kdistanceNode_targetNode(root->right, k, target, ans);
    if (rd != -1)
    {
        kDown(root, k - rd, root->right, ans);
        return rd + 1;
    }

    return -1;
}
```
## Views of trees.
```cpp

void width(Node *root, int hd, int *ans)
{
    if (!root) return;
    ans[0] = min(ans[0], hd);
    ans[1] = max(ans[1], hd);
    if (root->left) width(root->left, hd - 1, ans);
    if (root->right) width(root->right, hd + 1, ans);
}

class Pair1
{
public:
    Pair1(int hd, Node *node) : hd(hd), node(node) {}
    int hd; Node *node;
};

vvi verticalOrderTraversal(Node *root)
{
    int minMax[2] = {0};
    width(root, 0, minMax);
    queue<Pair1> que;
    int n = minMax[1] + abs(minMax[0]) + 1;
    vvi ans(n);
    que.push(Pair1(abs(minMax[0]), root));

    while (!que.empty())
    {
        int size = que.size();
        while (size-- > 0)
        {
            Pair1 temp = que.front();
            que.pop();
            ans[temp.hd].pb(temp.node->data);
            if (temp.node->left)
                que.push(Pair1(temp.hd - 1, temp.node->left));
            if (temp.node->right)
                que.push(Pair1(temp.hd + 1, temp.node->right));
        }
    }
 return ans
}
```
## Problem on Paths.
 >   **a. Single Path:** check ans from left or right, if found return the same ans immediately.
```cpp
// root-to-leaf paths where path sum equals targetSum.
bool hasPathSum(Node *root, int targetSum)
{
    if (!root) return false;
    if (!root->left && !root->right) return targetSum - root->data == 0;
    return hasPathSum(root->left, targetSum - root->data) || hasPathSum(root->right, targetSum - root->data);
}
```    
 >   **b. All Path:** check ans from left and right, if found then store the ans[both] return at the end. Let all possible solution is explored.
 ```cpp
 bool nodeToRootPath(Node *root, int data, vector<Node *> &nodeRootList)
{
    if (root == nullptr) return false;
    if (root->data == data)
    {
        nodeRootList.push_back(root);
        return true;
    }
    bool res = nodeToRootPath(root->left, data, nodeRootList) || nodeToRootPath(root->right, data, nodeRootList);
    if (res == true) nodeRootList.push_back(root);
    return res;
}
 ```

## LCA.
```java
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==null || root==p || root==q)return root;
        TreeNode left=lowestCommonAncestor(root.left,p,q);
        TreeNode right=lowestCommonAncestor(root.right,p,q);
        if(left==null)return right;
        else if(right==null)return left;
        return root;
    }
```
## Diameter
>**a. Naive Approach:** for each node find solution from scratch.
```cpp
int height(Node *root)
{
    return !root ? -1 : max(height(root->left), height(root->right)) + 1;
}

int diameter(Node *root)
{
    if (!root)
        return 0;

    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int diameter_root_inc = leftHeight + rightHeight + 2;

    return max(max(leftDiameter, rightDiameter), diameter_root_inc);
}
```
    
>**b. DP on Trees:** 

    1. Build ans and store it and then return result the val for parent node to build ans, and so on.
```java
//(diameter,height)
Pair<Integer,Integer> diameter(TreeNode root){
    if(root==null) return new Pair<>(0,-1);

    Pair<Integer,Integer> left=diameter(root.left);
    Pair<Integer,Integer> right=diameter(root.right);
    
    int dia=Math.max(left.getValue()+right.getValue()+2,Math.max(left.getKey(),right.getKey()));
    int height=1+Math.max(left.getValue(),right.getValue());
    return new Pair<>(dia,height);
}
```

    2. Build  ans and store it in global variable and also return value for parent node to build ans to optimize global solution.
```cpp
int diameter = 0;
int diameter(Node *root)
{
    if (!root) return -1;
    int leftHeight = diameter(root->left);
    int rightHeight = diameter(root->right);
    diameter = max(diameter, leftHeight + rightHeight + 2);
    return max(leftHeight, rightHeight) + 1;
}

```
