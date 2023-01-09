// Given a list of Integers(array) & a number K.
// Task is to "Find MAXIMUM AVERAGE of Contiguous subarray of size k."

// Example 1 :
//     Nums : [-10,5,-6,8,-7,2,-4,8,-6,7] , K : 3
//     Output : 3.0
//     Explanation : average of 8,-6,7 is maximum

// Example 2 :
//     Nums : [1,2,-3,-4,5,-6] , K = 2
//     Output : 1.5

#include "../header.h"
double solve(vi &arr, int k)
{
    int i = 0, sum = 0, n = arr.size(), ans = INT_MIN;
    while (i < k)
        sum += arr[i++];
    ans = sum;
    for (; i < n; i++)
    {
        sum = sum - arr[i - k] + arr[i];
        ans = max(ans, sum);
    }
    return ans * 1.0 / k;
}
int main()
{
    cout << "hello world!\n";
    int n, k;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cin >> k;
    cout << solve(arr, k) << endl;
}

/*
10
-10 5 -6 8 -7 2 -4 8 -6 7
3

**
6
1 2 -3 -4 5 -6
2
*/