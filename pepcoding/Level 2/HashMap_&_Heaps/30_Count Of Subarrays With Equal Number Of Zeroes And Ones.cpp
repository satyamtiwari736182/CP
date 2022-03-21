#include "../header.h"

int solve(vi &arr)
{
    map<int, int> hashmap;
    hashmap[0] = 1;
    int sum = 0, count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i] ? 1 : -1;

        if (hashmap.count(sum) == 0)
            hashmap[sum]++;
        else
        {
            count += hashmap[sum];
            hashmap[sum]++;
        }
    }

    return count;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    test(t)
    {
        int n;
        cin >> n;
        vi arr;
        rvarr(arr, 0, n);

        cout << "\n============================================\n";
        cout << solve(arr);

        cout << "\n============================================\n";
    }

    return 0;
}

// 2

// 6
// 0 1 1 0 1 1

// 13
// 0 0 1 0 1 0 1 1 0 0 1 1 1
