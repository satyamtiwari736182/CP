// 1. Question will be provided with two Intervals Lists.
// 2. An interval is is defined as (sp,ep) i.e. sp --> starting point &  ep --> ending point of an interval
// 3. All intervals are closed in nature
// 4. Intervals[i] = [startingPointi,endingPointi]
// 5. Both interval lists are sorted in nature(sorted based upon starting time of each interval).

// Task is to "find & print all intersection of intervals from both interval lists(intervals from list 1 & list 2).".

// Example 1 :
//     list_1 : [[1,3]]
//     list_2 : [[2,5]]
//     Output : [[2,3]]
//     Explanation : interval from list 1 starts @ 1 & ends @ 3 where as interval from list 2 starts @ 2 & ends @ 5 thus intersection(time span common in intervals from both lists) is {2,3}.

// Example 2 :
//     list_1 : [[1,3]]
//     list_2 : [[4,5]]
//     Output : []
//     Explanation : there is no common time-span(i.e. no intersection)  between intervals from both given list.
// Example 3 :
//     list_1 : [[1,3] [5,10] [12,17]]
//     list_2 : [[2,4] [5,7] [9,13]]
//     Output : [[2,3] [5,7] [9,10] [12,13]]

// 1
// 1 3
// 1
// 2 5