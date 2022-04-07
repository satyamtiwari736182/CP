// You are given an array(of integers) of length n.
// You are required to answer q queries.

// Queries can be of two types
// 0. 0 l r : In this you have to return sum of all elements arr[i] for i in l<=i<=r.
// 1. 1 l r val: In this query u have to increase all elements in this interval [l, r] by val.

// To do the above task u have to create a datastructure as follows :-

// Implement the SegmentTree class:
// 1. SegmentTree(int arr[]): Initializes the SegmentTree object with an array,
// 2. void update(int l, int r, int val): increase all elements in this interval [l, r] by val,
// 3. int query(int l, int r): return sum of all elements arr[i] for which i is in range [l, r].


// 8
// 0
// 10
// 10
// -1
// 5
// 8
// 10
// 2
// 5
// 0 7 7
// 1 4 6 1
// 0 2 4
// 1 5 5 7
// 0 3 7

