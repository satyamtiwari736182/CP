// 1. You are given an array(arr) of integers. Values may be duplicated.
// 2. You have to find the length of the largest subarray with contiguous elements.

// Note -> The contiguous elements can be in any order(not necessarily in increasing order).



#include "../header.h"

int solution(vi &arr)
{
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int minimum = arr[i];
        int maximum = arr[i];

        set<int> distinct_ele;
        distinct_ele.insert(arr[i]);

        for (int j = i + 1; j < arr.size(); j++)
        {
            if (distinct_ele.find(arr[j]) != distinct_ele.end())
                break;

            distinct_ele.insert(arr[j]);

            minimum = min(minimum, arr[j]);
            maximum = max(maximum, arr[j]);

            if (maximum - minimum == j - i)
                cnt = max(cnt, j - i + 1);
        }
    }

    return cnt;
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

        cout << solution(arr);

        cout << "\n============================================\n";
    }
    return 0;
}

// 2

// 3
// 10 12 11

// 15
// 9 2 7 5 6 23 24 22 23 19 17 16 18 39 0
