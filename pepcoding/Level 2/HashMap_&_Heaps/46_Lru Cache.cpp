// Implement LRU(Least Recently Used Cache), Task is to complete implementations of put(),get().
// 1. capacity : capacity of the cache will be provided as input.
// 2. put(key,value) : add the key-value pair to the Cache & override if the pair is already present in cache;
// 3. get(key) : get the value associated with the key, return "-1" incase key-value pair doesn't exists

// NOTE : Watch Question video to get better understanding of problem.
// Example  : 
//     Input : Start 3
//             put 1 10
//             put 2 20
//             put 3 30
//             get 1
//             put 1 15
//             get 1
//             get 2
//             put 4 40
//             get 3
//             get 4
//             Stop
            
            
//     Output : 10
//              15
//              20
//              -1
//              40


// start 3
// put 1 10
// put 2 20
// put 3 30
// put 4 40
// get 1
// stop