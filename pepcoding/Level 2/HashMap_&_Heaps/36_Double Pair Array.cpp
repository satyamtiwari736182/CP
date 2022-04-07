#include "../header.h"

bool solve(vi &arr)
{
    if (arr.size() == 0)
        return true;
    map<int, int> hashmap;
    for (int val : arr)
        hashmap[val]++;

    sort(all(arr), [&](auto a, auto b)
         { return (abs(a) < abs(b)); });

    for (int ele : arr)
    {
        if (hashmap[ele] == 0)
            continue;
        if (hashmap[2 * ele] == 0)
            return false;
        hashmap[ele]--;
        hashmap[2 * ele]--;
    }

    return true;
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

// 3

// 4
// 3 1 3 6

// 12
// 8 8 4 2 0 2 1 4 0 16 8 4

// 16
// -8 -3 8 8 4 -6 -4 2 0 2 1 4 0 16 8 4
