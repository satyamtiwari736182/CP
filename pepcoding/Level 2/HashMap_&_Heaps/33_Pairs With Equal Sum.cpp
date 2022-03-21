// 1. You are given an array(arr) of distinct integers.
// 2. You have to find if there are two pairs(A, B) and (C, D) present in the given array which satisfies the condition A+B = C+D.

#include "../header.h"

int solve(vi &arr)
{
    set<int> hashset;
    int sum = 0;
    for (int i = 0; i < arr.size() - 1; i++)
        for (int j = i + 1; j < arr.size(); j++)
        {
            sum = arr[i] + arr[j];
            if (hashset.count(sum))
                return true;
            else
                hashset.insert(sum);
        }

    return false;
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
// 2 9 3 5 8 6 4

// 8
// 1 2 998 72 87576 21 45 -1
