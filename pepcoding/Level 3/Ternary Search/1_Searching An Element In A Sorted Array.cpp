// Given a sorted array of size N and an integer, K. Check if K is present in the array or not using ternary search.
// Ternary Search - It is a divide and conquers algorithm that can be used to find an element in an array. It is similar to binary search where we divide the array into two parts but in this algorithm, we divide the given array into three parts and determine which has the key (searched element).


#include "../header.h"

int ternary_search(vi &arr, int val)
{
    int left = 0, right = arr.size() - 1;
    while (left <= right)
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        // 1. found
        if (arr[mid1] == val)
            return mid1;
        else if (arr[mid2] == val)
            return mid2;
        // 2.lies in left part
        else if (val < arr[mid1])
            right = mid1 - 1;
        // 3.lies in right part
        else if (val > arr[mid2])
            left = mid2 + 1;
        // 4.lies in-between left and right
        else
        {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
}

void solve()
{
    int n, val;
    cin >> n >> val;
    vi arr(n + 1);
    rarr(arr, 1, n + 1);

    int idx = ternary_search(arr, val);
    cout << idx << endl;
}
int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    // cin >> t;
    test(t)
    {
        solve();
        cout << "\n------------------------------\n";
    }

    return 0;
}


// 5 2
// 1 2 3 4 5