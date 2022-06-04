
// 1. Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// 2. Discards the least recently used items first. This algorithm requires keeping track of what 
//    was used when, which is expensive if one wants to make sure the algorithm always discards 
//    the least recently used item. General implementations of this technique require keeping 
//    "age bits" for cache-lines and track the "Least Recently Used" cache-line based on age-bits. 
//    In such an implementation, every time a cache-line is used, the age of all other cache-lines changes
   
// 3. mplement the LRUCache class: 
//       3.1 LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
//       3.2 int get(int key) Return the value of the key if the key exists, otherwise return -1.
//       3.3 void put(int key, int value) Update the value of the key if the key exists. Otherwise, 
//           add the key-value pair to the cache. If the number of keys exceeds the capacity from this 
//           operation, evict the least recently used key.

// 4. Could you do get and put in O(1) time complexity? 



// 5 2
// 0 5 2
// 0 6 8
// 0 5 3
// 0 4 7
// 1 5