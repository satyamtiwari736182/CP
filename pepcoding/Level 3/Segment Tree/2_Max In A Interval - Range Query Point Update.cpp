// You are given an array(of integers) of length n.
// You are required to answer q queries.

// Queries can be of two types
// 0. 0 pos val : In this you have to update arr[pos] to val.
// 1. 1 l r: In this query u have to find the max among all elements in this interval.


// To do the above task u have to create a datastructure as follows :-

// Implement the SegmentTree class:
// 1. SegmentTree(int arr[]): Initializes the SegmentTree object with an array,
// 2. void update(int pos, int val): updates the arr[pos] to val,
// 3. int query(int l, int r): return max of all element's in interval [l, r].

// Can u do it in O(log(n)) or better Time Complexity.


// 4
// 1
// 2
// 3
// 4
// 10
// 1 0 3
// 0 1 3
// 1 0 3
// 1 1 2
// 0 2 5
// 1 2 2
// 1 2 3
// 1 0 1
// 1 0 2
// 1 1 3