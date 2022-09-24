// 1. You are given an array(arr) of integers and a number K.
// 2. You have to find the count of distinct numbers in all windows of size k.

#include "../header.h"

vi solution(vi &arr, int k)
{
    vi distinct_cnt;
    map<int, int> hashmap;
    for (int i = 0; i < k - 1; i++)
        hashmap[arr[i]]++;

    for (int j = 0, i = k - 1; i < arr.size(); i++, j++)
    {
        hashmap[arr[i]]++;
        distinct_cnt.pb(hashmap.size());

        int cnt = hashmap[arr[j]];
        if (cnt == 1)
            hashmap.erase(arr[j]);
        else
            hashmap[arr[j]]--;
    }

    return distinct_cnt;
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
        int k;
        cin >> k;

        cout << "\n============================================\n";
        vi ans = solution(arr, k);
        for (int cnt : ans)
            cout << cnt << " ";
        cout << "\n============================================\n";
    }
    return 0;
}

// 2

// 7
// 1 2 1 3 4 2 3
// 4

// 16
// 2 5 5 6 3 2 3 2 4 5 2 2 2 2 3 6
// 4