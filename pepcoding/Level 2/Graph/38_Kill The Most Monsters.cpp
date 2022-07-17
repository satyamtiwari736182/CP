// On a 2D plane, we place n monsters at some integer coordinate points. Each coordinate point may have at most one monster.

// A monster can be removed if it shares either the same row or the same column as another monster that has not been removed.

// Given an array monsters of length n where monsters[i] = [xi, yi] represents the location of the ith monster, return the largest possible number of monsters that can be removed.

// Example 1:

//     Input: monsters = [[0,0],[0,2],[1,1],[2,0],[2,2]]
//     Output: 3

// Explanation: One way to make 3 moves is as follows:
// 1. Remove monster [2,2] because it shares the same row as [2,0].
// 2. Remove monster [2,0] because it shares the same column as [0,0].
// 3. Remove monster [0,2] because it shares the same row as [0,0].
// monsters [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.



// 6
// 0
// 0
// 0
// 1
// 1
// 0
// 1
// 2
// 2
// 1
// 2
// 2