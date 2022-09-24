// 1. You are given an array of integers(arr) and a number K.
// 2. You have to find length of the longest subarray whose sum is divisible by K.



#include "../header.h"

int K_sum(vi &arr, int k)
{
    map<int, int> hashmap;
    hashmap[0] = -1;
    int sum = 0, rem = 0, count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        rem = (sum % k + k) % k;

        if (hashmap.count(rem) == 0)
            hashmap[rem] = i;
        else
            count = max(count, i - hashmap[rem]);
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
        int n, k;
        cin >> n;
        vi arr;
        rvarr(arr, 0, n);
        cin >> k;

        cout << "\n============================================\n";
        cout << K_sum(arr, k);

        cout << "\n============================================\n";
    }

    return 0;
}

// 2

// 6
// 2 7 6 1 4 5
// 3

// 8
// -3 -9 -4 8 5 4 2 6
// 7