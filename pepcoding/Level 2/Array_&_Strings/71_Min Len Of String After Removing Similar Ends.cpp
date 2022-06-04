// Given a String of Characters.
// Task is to "Find Minimum length of string after removing similar ends ?."

// Example 1 : 
//     Intput : "pepepep"
//     Output : 1
//     Explanation : After removing "pep" from start & end of String will leave only 1 length string.

// Example 2 : 
//     Input : "aaabbcdaoddcccbaa"
//     Ouput : 2
//     Explanation : 
//             1. remove "aaa" from left end & "aa" from right end(as they have similar characters)
//             2. remove "bb" from left end & "b" from right end(as they have similar characters)
//             3. remove "c" from left end & "ccc" from right end(as they have similar characters)
//             4. remove "d" from left end & "dd" from right end(as they have similar characters)
//             5. removing similars will ensure a String of length 2 i.e. "ao"
// Example 3 : 
//     Input : "abcd"
//     Output : 4
//     Explanation : No similar characters on both ends.

// Example 4 : 
//     Input : "aabccba"
//     Output : 0


// pepepep
