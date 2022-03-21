#include "../header.h"

int solve(vi &arr)
{
    map<string, int> hashmap;
    hashmap["0#0"] = -1;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0, count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
            cnt0++;
        else if (arr[i] == 1)
            cnt1++;
        else
            cnt2++;

        int diff1_0 = cnt1 - cnt0;
        int diff2_1 = cnt2 - cnt1;
        string diff = to_string(diff1_0) + "#" + to_string(diff2_1);

        if (hashmap.count(diff) == 0)
            hashmap[diff] = i;
        else
            count = max(count, i - hashmap[diff]);
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

// 7
// 0 1 0 2 0 1 0

// 13
// 1 1 2 0 1 0 1 2 1 2 2 0 1
