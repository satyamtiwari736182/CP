// 1. You are given n number of domino shaped bipolar magnets.
// 2. You have to place these magnets in M*N following the conditions.
// 3. Conditions are -
//    a. Each box of 1*2 or 2*1 can contain a magnet or can be empty.
//    b. Empty box can be represented by X's and magnets are represented by + and 
//     - sign.
//    c. Digits along left and top side of the board represents the number of + in 
//     corresponding rows and columns.
//    d. Digits along right and bottom of the board represents the number of - in 
//     corresponding rows and columns.
//     e. -1 denotes that the corresponding row and column can have any number of 
//     +  and - signs.
//     f. No two adjacent cell can have the same sign.


// Note -> Check out the question video and write the recursive code as it is intended without changing signature. The judge can't force you but intends you to teach a concept.


/*

5 6
LRLRTT
LRLRBB
TTTTLR
BBBBTT
LRLRBB
1 -1 -1 2 1 -1
2 3 -1 -1 -1
-1 -1 -1 1 -1
2 -1 -1 2 -1 3

*/