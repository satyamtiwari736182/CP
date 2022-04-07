// 1.Given an integer array instructions.
// 2.you are asked to create a sorted array from the elements in instructions. You start with another empty array nums. For each element from left to right in instructions, insert it into nums.
// 3. The cost of each insertion is the minimum of the following:
//      a)The number of elements currently in nums that are strictly less than instructions[i].
//      b)The number of elements currently in nums that are strictly greater than instructions[i].

// 4.For example, if inserting element 4 into nums = [2,3,4,5], the cost of insertion is min(2, 1) (elements 2 and 3 are less than 4, element 5 is greater than 4) and nums will become [2,3,4,4,5].
// 5.Return the total cost to insert all elements from instructions into nums.



// 6
// 1 2 3 6 5 4