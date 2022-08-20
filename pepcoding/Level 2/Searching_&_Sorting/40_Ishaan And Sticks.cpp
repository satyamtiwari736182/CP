// Ishaan has a craving for sticks. He has N sticks. He observes that some of his sticks are of the same length, and thus he can make squares out of those.
// He wants to know how big a square he can make using those sticks as sides. Since the number of sticks is large, he can't do that manually. Can you tell him the maximum area of the biggest square that can be formed?
// Also, calculate how many such squares can be made using the sticks.


#include "../header.h"

void maxAreaSquareCnt(vi &arr)
{
    unordered_map<int, int> hashmap;
    for (int val : arr)
        hashmap[val]++;

    int stick_size = 0, cnt = 0;
    for (pi pr : hashmap)
        if (pr.fs >= stick_size && pr.se >= 4)
            stick_size = pr.fs, cnt = pr.se / 4;

    cout << stick_size * stick_size << ", " << cnt << endl;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr(n);
        rarr(arr, 0, n);

        cout << "\n============================================\n";
        maxAreaSquareCnt(arr);
        cout << "\n============================================\n";
    }
    return 0;
}

/*
15
4 4 4 4 3 4 4 4 4 2 4 4 3 3 3
*/