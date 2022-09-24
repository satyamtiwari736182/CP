// 1. You are given an array(arr) which contains only 0's and 1's.
// 2. You have to find the maximum number of consecutive 1's in the given array if you can flip at most one zero.


#include "../header.h"

int solution(vi &arr, int k)
{
    map<int, int> hashmap;
    int ans = 0;
    int n = arr.size();
    int i = -1, j = -1;
    while (true)
    {
        bool f1 = false, f2 = false;

        while (i < n - 1)
        {
            f1 = true;
            i++;
            hashmap[arr[i]]++;
            if (hashmap[0] > k)
                break;
            ans = max(ans, i - j);
        }

        while (j < i)
        {
            f2 = true;
            j++;
            hashmap[arr[j]]--;

            if (hashmap[0] == k)
                break;
        }

        if (f1 == false && f2 == false)
            break;
    }
    return ans;
}
int main()
{

    cout << "\nHello world!" << endl;

    int n, t, k;

    cin >> t;
    test(t)
    {
        vi arr;
        cin >> n;
        rvarr(arr, 0, n);
        cin >> k;
        cout << "\n============================================\n";
        cout << "\n"
             << solution(arr, k) << endl;
        cout << "\n============================================\n";
    }

    return 0;
}

// 2
// 6
// 1 1 0 0 1 1
// 1

// 13
// 1 1 0 1 0 0 1 1 0 1 0 1 1
// 2