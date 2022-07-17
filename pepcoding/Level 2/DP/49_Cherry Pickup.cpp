// 1. You are given a number N, which represents the rows and columns of a 2-D matrix.
// 2. Matrix contains only three values - 
//    a. Cell is empty.
//    b. Cell contains a cherry.
//    c. Cell contains a thorn and you can not pass through this cell.
// 3. You have to find the maximum number of cherries that you can collect following these rules :
//    a. You have to start from (0,0) and travel till (N-1,N-1) by moving right or down, 
//     one step at a time.
//    b. After reaching (N-1,N-1), you have to come back to (0,0) by moving left or up, 
//     one step at a time.   

// Note -> If there is no valid path between the top-left cell and bottom-right cell, then no cherries can be collected.


// 3
// 0 
// 1 
// -1
// 1 
// 0
// -1
// 1 
// 1  
// 1