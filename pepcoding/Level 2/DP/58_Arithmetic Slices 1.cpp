// 1. You are given an array(arr) of integers.
// 2. You have to find the count of arithmetic slices in the given array.
// 3. Arithmetic slice is defined as the sub-array having all its elements in A.P and the length of sub-array should be greater than or equal to 3.

#include "../header.h"

int solution(vi &arr)
{
    vi dp(arr.size());
    int ans = 0;

    for (int i = 2; i < arr.size(); i++)
        if (arr[i] - arr[i - 1] == arr[i - 1] - arr[i - 2])
            dp[i] = dp[i - 1] + 1, ans += dp[i];

    return ans;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cout << "\n------------\n";
    cout << solution(arr) << endl;

    //------------------------------------------------------

    return 0;
}

/*
4
1 2 3 4
*/
