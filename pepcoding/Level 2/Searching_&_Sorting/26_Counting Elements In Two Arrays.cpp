// Given two unsorted arrays arr1[] and arr2[]. They may contain duplicates. For each element in arr1[] count elements less than or equal to it in array arr2[].

// Given an unsorted array arr[] of n positive integers. Find the number of triangles that can be formed with three different array elements as lengths of three sides of triangles.

#include "../header.h"

vector<int> solve(vi &arr, vi &arr2)
{
    //  Write your code here
    vector<int> res(arr.size());
    sort(all(arr2));
    for (int i = 0; i < arr.size(); i++)
    {
        int x = arr[i];
        int end = -1;
        int left = 0, right = arr2.size() - 1;
        // for end index
        int mid = 0;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (arr2[mid] <= x)
                end = mid, left = mid + 1;
            else if (x < arr2[mid])
                right = mid - 1;
        }
        res[i] = end + 1;
    }
    return res;
}

int main()
{
    cout << "\nHello world!" << endl;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr1;
        rvarr(arr1, 0, n);
        cin >> n;
        vi arr2;
        rvarr(arr2, 0, n);

        cout << "\n============================================\n";

        vi res = solve(arr1, arr2);
        parr(res, res.size());

        cout << "\n============================================\n";
    }
    return 0;
}

/*
6
1 2 3 4 7 9
6
0 1 2 1 1 4
*/