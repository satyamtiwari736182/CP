// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

#include "../header.h"
double solve(vi &arr1, vi &arr2)
{
    if (arr2.size() > arr1.size())
        swap(arr1, arr2);
    int isodd = (arr1.size() + arr2.size()) & 1;
    int total_ele = arr1.size() + arr2.size();
    int low = 0, high = arr1.size();

    while (low <= high)
    {
        int aleft = (low + high) / 2;
        int bleft = (total_ele + 1) / 2 - aleft;

        int aleft_1 = aleft == 0 ? INT_MIN : arr1[aleft - 1];
        int aleft_ = aleft == arr1.size() ? INT_MAX : arr1[aleft];
        int bleft_1 = bleft == 0 ? INT_MIN : arr2[bleft - 1];
        int bleft_ = bleft == arr2.size() ? INT_MAX : arr2[bleft];

        // valid segregation
        if (aleft_1 <= bleft_ && bleft_1 <= aleft_)
        {
            double median = 0.0;
            if (isodd)
                median = max(aleft_1, bleft_1);
            else
                median = (max(aleft_1, bleft_1) + min(aleft_, bleft_)) / 2.0;
            return median;
        }
        // invalid segregation
        else if (aleft_1 > bleft_)
            high = aleft - 1;
        else if (bleft_1 > aleft_)
            low = aleft + 1;
    }

    return 0;
}
int main()
{
    cout << "\nHello world!" << endl;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr1, arr2;
        rvarr(arr1, 0, n);
        cin >> n;
        rvarr(arr2, 0, n);

        cout << "\n============================================\n";

        cout << solve(arr1, arr2);

        cout << "\n============================================\n";
    }
    return 0;
}

// 1

// 5
// 3 5 7 9 12
// 3
// 4 6 14