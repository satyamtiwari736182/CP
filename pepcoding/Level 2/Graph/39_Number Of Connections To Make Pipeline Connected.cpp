// There are n houses numbered from 0 to n-1 connected by pipes forming a network where connections[i] = [a, b] represents a connection between houses a and b. 
// Any house can reach any other house directly or indirectly through the network.

// Given an initial pipeline network connections. You can extract certain pipes between two directly connected houses, 
// and place them between any pair of disconnected houses to make them directly connected. 

// Return the minimum number of times you need to do this in order to make all the houses connected. 
// If it's not possible, return -1. 

// Example 1:

// Input: n = 4, connections = [[0,1],[0,2],[1,2]]
// Output: 1
// Explanation: Remove pipe between house 1 and 2 and place between houses 1 and 3.


// 4
// 3
// 0
// 1
// 0
// 2
// 1
// 2