// 1. IntervalList & a newInterval will be given as input.
// 2. IntervalList is a sequence of sorted(on the basis of start time) & non-overlapping intervals.
// 3. any interval[i] (from IntervalList) = [startTime,endTime].
// 4. a newInterval will also be passed as input.
// Task is to "Insert this newInterval to the given sorted IntervalList".
// NOTE : Inserting this newInterval may lead to merging of intervals.

// Example 1 : 
//     IntervalList = [[1,5][8,10]]
//     newInterval = [3,8]
//     OUTPUT : [[1,10]].
//     Explanation : after inserting newInterval (3,8) ,every interval can now be merged to (1,10).

// Example 2 : 
//     IntervalList = [[1,5][8,10]]
//     newInterval = [3,6]
//     OUTPUT : [[1,6][8,10]].

// Example 3 :
//     IntervalList = [[3,5][8,10]]
//     newInterval = [1,2]
//     OUTPUT : [[1,2][3,5][8,10]].
    
// Example 4 : 
//     IntervalList = []
//     newInterval = [3,8]
//     OUTPUT : [[3,8]].

// 5
// 1 5
// 7 9
// 10 13
// 16 19
// 20 25
// 12 20