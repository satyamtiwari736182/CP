// Three players Alice and Bob and Charlie are playing a game. There are two tables, on the first table, there are N heaps containing A[1],A[2].... A[n] coins, on the second table , there are M heaps containing B[1], B[2]... B[m] coins.
// Initially, Alice is playing at the first table and Bob is playing at the second table. The players take their turns in this order: Charlie, Alice, Bob, Charlie, etc.
// Bob and alice in their turn can remove as much coin as they want(min is 1) from any one pile of their respective tables. Whoever cannot remove any stone from a pile loses.
// Charlie does not play at any table. Instead, on his turn, he decides if Alice and Bob should keep playing at their respective tables or swap places.
// Alice and Charlie are buddies and they cooperate, playing in the optimal way that results in Alice's victory (if possible). Find out whether alice will win or bob.


// 6 7
// 24 6 10 56 9 1
// 0 6 24 1 9 56 10