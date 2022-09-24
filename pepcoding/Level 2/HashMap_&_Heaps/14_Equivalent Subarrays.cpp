// 1. You are given an array of integers(arr).
// 2. You have to find the count of equivalent subarrays.
// 3. A subarray is equivalent if,
//    count of unique integers in the subarray = count of unique integers in the given array.



#include "../header.h"

int solution(vi &arr)
{
    set<int> hashset;
    for (int val : arr)
        hashset.insert(val);

    int ans = 0;
    int k = hashset.size();
    int n = arr.size();
    int i = -1, j = -1;
    map<int, int> hashmap;
    while (true)
    {
        bool f1 = false, f2 = false;

        while (i < n - 1)
        {
            f1 = true;
            i++;
            hashmap[arr[i]]++;

            if (hashmap.size() < k)
                continue;
            else
                break;
        }

        while (j < i)
        {
            f2 = true;
            j++;
            if (hashmap.size() == k)
            {
                // cout << i << j << " ";
                ans += n - i;
            }

            hashmap[arr[j]]--;
            if (hashmap[arr[j]] == 0)
            {
                hashmap.erase(arr[j]);
                break;
            }
        }

        if (f1 == false && f2 == false)
            break;
    }
    return ans;
}
int main()
{

    cout << "\nHello world!" << endl;

    int n, t;

    cin >> t;
    test(t)
    {
        vi arr;
        cin >> n;
        rvarr(arr, 0, n);
        cout << "\n============================================\n";
        cout << "\n"
             << solution(arr) << endl;
        cout << "\n============================================\n";
    }

    return 0;
}

// 2
// 5
// 2 1 3 2 3

// 10
// 2 5 3 5 2 4 1 3 1 4