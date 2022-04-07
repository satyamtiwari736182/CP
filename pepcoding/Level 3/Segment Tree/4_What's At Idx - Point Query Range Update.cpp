// You are given an array(of integers) of length n.
// You are required to answer q queries.

// Queries can be of two types
// 0. 0 ind : In this you have to tell the value of arr[ind].
// 1. 1 l r val: In this query u have to increase all elements in this interval [l, r] by val.

// To do the above task u have to create a datastructure as follows :-

// Implement the SegmentTree class:
// 1. SegmentTree(int arr[]): Initializes the SegmentTree object with an array,
// 2. void update(int l, int r, int val): increase all elements in this interval [l, r] by val,
// 3. int query(int ind): return arr[ind].


// 8
// 4
// 3
// 9
// 3
// 9
// 8
// 7
// 2
// 5
// 1 4 6 0
// 0 7
// 1 0 3 4
// 0 4
// 0 5
