// 1. You are given a number N.
//  2. Assume you have an array of length N initialised with all 0's.
//  3. You are also given K update operations.
//  4. Each operation contain 3 numbers: startIndex, endIndex and inc and updates each element of the subarray arr[startIndex, endIndex](both inclusive) with inc.
//  5. You have to find the resultant array when all K operations are executed.
//  6. display is a utility function, feel free to use it for debugging purposes.
//  7. main takes input from the users.
//  8. This is a functional problem. 
//  9. You have to complete the getModifiedArray function. It takes as input a length and a 2D array of update operations. It should return the modified array.
//  10. Don't change the code of main and display.

// Expected Complexity : O(n+k)


// 4 
// 3
// 0 2 -1
// 2 2 2
// 1 3 1