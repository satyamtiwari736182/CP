// https://leetcode.com/problems/brick-wall/

#include "../header.h"

int leastBricks(vvi &wall)
{
    map<int, int> hashmap; //(index=>splitCount)
    int maxSplit = 0;
    for (vi &bricks : wall)
    {
        int prefixSum = 0;
        for (int i = 0; i < bricks.size() - 1; i++)
        {
            int brickSize = bricks[i];
            prefixSum += brickSize; // column index of split
            hashmap[prefixSum]++;
            maxSplit = max(maxSplit, hashmap[prefixSum]);
        }
    }

    // for (auto pr : hashmap)
    //     cout << pr.fs << " -> " << pr.se << endl;
    // cout << endl;
    return wall.size() - maxSplit;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    test(t)
    {
        int n;
        cin >> n;
        vvi arr(n);
        for (int i = 0; i < n; i++)
        {
            vi arr1;
            string str;
            int type = 0;
            fflush(stdin), getline(cin, str);
            str_to_tok(str, ' ', arr1, type);
            arr[i] = arr1;
        }

        cout << "\n============================================\n";
        cout << leastBricks(arr);
        cout << "\n============================================\n";
    }

    return 0;
}

/*
6
1 2 2 1
3 1 2
1 3 2
2 4
3 1 2
1 3 1 1
*/