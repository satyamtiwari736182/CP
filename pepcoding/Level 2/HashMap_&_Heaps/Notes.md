Types of Problems

- [1] Numer of Employee Under every manager
  => HashMap used to build tree

- [2] Largest subarray with zero sum
  => remembering the previously occured value.

- [3] Longest substring with exactly k Unique characters
  i. keep Acquiring the val till [codition] is not met.
  ii. Collect [required ans] when [condition] is met
  iii. keep Releasing the val till [condition] is voilated

- [4] Valid Anagram
  => Frequency map/count

- [*] Others
  [5] Rabbits in the forest
  [6] Brick Wall
  [7]Qno.38

- a = n2*k + m1 , b = n2*k + m2
  a-b = (n2-n1)*k + (m1-m2)
  if m1=m2 => (a-b)=n*k;

### State Transition
```md
# LeetCode - 123
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
```
```java
public int maxProfit(int[] prices) {
    int boughtState1=-prices[0],soldState1=Integer.MIN_VALUE,boughtState2=Integer.MIN_VALUE,soldState2=Integer.MIN_VALUE; //profit
    for(int i=1;i<prices.length;i++){
        soldState1=Math.max(soldState1,boughtState1+prices[i]);
        boughtState2=Math.max(boughtState2,soldState1-prices[i]);
        soldState2=Math.max(soldState2,boughtState2+prices[i]);
        boughtState1=Math.max(boughtState1,-prices[i]);
    }
    return Math.max(0,soldState2);
}
```

#### Balanced BST
```md
# LeetCode - 1382
Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
```
```java
int getHeight(TreeNode root){
    if(root==null) return -1;
    return 1 + Math.max(getHeight(root.left),getHeight(root.right));
}
int getBalanceFactor(TreeNode root){
    if(root==null) return 0;
    return getHeight(root.left) - getHeight(root.right);
}
TreeNode rotateRight(TreeNode x,TreeNode parent){
    TreeNode y=x.left;
    x.left=y.right;
    y.right=x;

    if(x == parent.left) parent.left=y;
    if(x == parent.right) parent.right=y;

    return y;
}
TreeNode rotateLeft(TreeNode x,TreeNode parent){
    TreeNode y=x.right;
    x.right=y.left;
    y.left=x;
    
    if(x == parent.left) parent.left=y;
    if(x == parent.right) parent.right=y;
    return y;
}
public void balanceBST(TreeNode root, TreeNode parent) {
    if(root==null) return;
    balanceBST(root.left,root);
    balanceBST(root.right,root);

    int balanceFactor=getBalanceFactor(root);
    if(balanceFactor > 1){
        if(getBalanceFactor(root.left) < 0) rotateLeft(root.left,root);
        balanceBST(rotateRight(root,parent),parent);
    }
    else if(balanceFactor < -1){
        if(getBalanceFactor(root.right) > 0) rotateRight(root.right,root);
        balanceBST(rotateLeft(root,parent),parent);
    }
}
public TreeNode balanceBST(TreeNode root) {
    TreeNode dummy=new TreeNode(0,root,null);
    balanceBST(root,dummy);
    return dummy.left;
}
```
```java
void inorder(TreeNode root,List<Integer> res){
    if(root==null)return;
    inorder(root.left,res);
    res.add(root.val);
    inorder(root.right,res);
}
public TreeNode balanceBST(List<Integer> res,int l,int r) {
    if(l>r) return null;
    if(l==r) return new TreeNode(res.get(l));
    int m=(l+r)/2;
    return new TreeNode(res.get(m),balanceBST(res,l,m-1),balanceBST(res,m+1,r));        
}
public TreeNode balanceBST(TreeNode root) {
    List<Integer> res=new ArrayList<>();
    inorder(root,res);
    return balanceBST(res,0,res.size()-1);
}
```