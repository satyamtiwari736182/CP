// 1. You are given an array of integers(arr) and a number K.
// 2. You have to find the count of subarrays whose sum equals k.


#include "../header.h"

int K_sum(vi &arr, int k)
{
    map<int, int> hashmap;
    hashmap[0] = 1;
    int sum = 0, count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        int sum_k = sum - k;

        hashmap[sum]++;
        if (hashmap.count(sum_k) != 0)
            count += hashmap[sum_k];
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

// 3
// 1 1 1
// 2

// 15
// 3 9 -2 4 1 -7 2 6 -5 8 -3 -7 6 2 1
// 5