// You are given a sequence of whole numbers {0,1,2,3 ... , N-1} defined in an array A. where A[i] = i here 0 <= i < N.
// You need to perform some queries with it. If the query is of
// Type 0: You are given two integer L and R.(0 <= L <= R < N) You need to find the K such that

// 	K =  Math.floor(P) : Integer just less than P, where P is defined as
// 	P = f(A[L]) + f(A[L+1]) + f(A[L+2]) .. f(A[R])	:   sum of f(A[i]) where L<=i<=R, and
// 	f(x) = cos(2*x) / (cos(x) - sin(x)) , where cos(x) - sin(x) can't be equal to zero.

// Type 1: You are given 3 integer L, R and D. (0 <= L <= R < N) and (-1000 <= D <= 1000)

// 	You need to add D to the numbers A[L], A[L+1], A[L+2]...A[R]  :  A[i] = A[i] + D where L<=i<=R

// 5 5
// 0 1 4
// 1 2 2 3
// 0 2 3
// 1 3 4 3
// 0 3 4
