// 1. You are given an array of positive integers in ascending order, which represents the position of stones in the river.
// 2. A frog is trying to cross a river. It can jump on a stone, but it must not jump into the water.
// 3. You have to find if the frog can cross the river by landing on the last stone.
// 4. The frog is on the first stone initially, and from first stone it can jump 1 unit only.
// 5. The frog can only jump k-1, k, or k+1 units in the forward direction, where k is the frog's last jump.


#include "../header.h"

bool solution(vi &stones)
{
    unordered_map<int, unordered_set<int>> hashmap;

    hashmap[stones[0]].insert(1);
    for (int i = 0; i < stones.size(); i++)
    {
        int currStone = stones[i];
        unordered_set<int> jumps = hashmap[currStone];
        for (int jump : jumps)
        {
            int pos = currStone + jump;

            if (pos == stones[stones.size() - 1])
                return true;

            if (jump - 1 > 0)
                hashmap[pos].insert(jump - 1);
            hashmap[pos].insert(jump);
            hashmap[pos].insert(jump + 1);
        }
    }
    return false;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);

    cout << "\n------------\n";
    cout << solution(arr) << endl;
    //------------------------------------------------------

    return 0;
}

/*
8
0 1 3 5 6 8 12 17

8
0 1 2 3 4 8 9 11
*/
