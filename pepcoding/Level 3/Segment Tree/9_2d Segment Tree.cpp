// Mr. Pepcoder has a 2D Array, and his Friend love to do operations on thearray. The operations can be a query or an update.

// For each query the Friend say four indices x1, y1, x2 and y2, and their father answers back with the sum of the elements of the rectangle whose top left index is x1, y1 and bottom right is x2, y2.

// When there is an update, the friend says index (x1,y1) and a value x , and Pepcoder will add x to arr[x1][y1] (so the new value of arr[x1][y1]  is arr[x1][y1] + x ).

// Because indexing the array from zero is too obscure for friend, all indices start from 1.


// 3 3
// 1 2 3 
// 4 5 6
// 7 8 9
// 5
// q 1 1 2 2
// q 1 2 3 3
// q 2 1 3 2
// u 1 1 1
// q 1 1 2 2

