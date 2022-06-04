// 1. A car moving in east direction has to make some pickups/drops(passengers) on the way.
// 2. Car has a limited capacity to carry passengers.
// 3. Given a List of Trips i.e. trip[i] = [pickup_location,drop_Location,num_passengers] , find out whether it is possible to make all trips on the way or not.
// NOTE: Car will only move in east directions i.e. no turn-around trip is possible.


// Task is to "Find out whether it is possible to make all trips on the way[YES] or not[NO]".


// Example 1 : 
//     trip[] = [[1,5,2],[4,8,1],[11,15,3]]
//     passengerCapacity : 3
//     output : YES
    

// Example 2 : 
//     trip[] : [[1,3,5]]
//     passengerCapacity : 4;
//     output : NO

// Example 3 :
//     trip[] : []
//     passengerCapacity : 2
//     output : YES

// Example 4 : 
//     trip[] = [[1,5,2],[4,8,2],[11,15,3]]
//     passengerCapacity : 3
//     output : NO


// 3
// 1 5 2
// 4 8 1
// 11 15 3
// 3