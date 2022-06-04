// 1. Question will be provided with "n" Intervals. An Interval is defined as (sp,ep) i.e. sp --> starting point &  ep --> ending point of an Interval (sp/ep are inclusive). Some Intervals may or maynot overlap eachother.
// 2. Intervals[i] = [startingPoint,endingPoint]
// Task is to "Merge all Overlapping Intervals".

// Example 1 : 
//     Input : [[1,3],[2,4],[6,8],[10,14],[7,9]]
//     Output : [[1,4],[6,9],[10,14]]

// Example 2 : 
//     Input : [[1,3],[3,15],[6,8],[10,14],[7,9]]
//     Output : [[1,3][3,15]]

// Example 3 : 
//     Input : [[1,3],[5,8],[10,19],[15,20],[9,9]]
//     Output : [[1,3],[5,8],[9,9],[10,20]]

// Note : If ending time of interval I1 is same as starting time of I2 then both will consider as separate Intervals.

// 5
// 1 3
// 8 10
// 7 8
// 9 15
// 2 6