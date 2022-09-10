// 1. You are given an array(arr) of positive numbers and two numbers M and K.
// 2. You have to find the maximum sum of M non-overlapping subarrays of size K.
// 3. The size of the given array(arr) is greater than M*K.

#include "../header.h"

int solution(vi &arr, int idx, int m, int k, vi &pSum)
{
    if (m == 0)
        return 0;
    if (idx >= arr.size())
        return 0;

    int excl = 0 + solution(arr, idx + 1, m, k, pSum);
    int incl = pSum[idx] + solution(arr, idx + k, m - 1, k, pSum);

    int ans = max(incl, excl);
    return ans;
}

int main()
{
    cout << "\nHello world!\n";
    int n, m, k;
    cin >> n;
    vi arr(n), pSum(n);
    rarr(arr, 0, n);

    cin >> m >> k;

    //------------------------------------------------------
    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += arr[i];

    pSum[0] = sum;
    for (int i = k, j = 0; i < n; i++, j++)
    {
        sum += arr[i] - arr[j];
        pSum[i - k + 1] = sum;
    }

    cout << "\n------------\n";
    cout << solution(arr, 0, m, k, pSum) << endl;

    return 0;
}

/*
7
2 10 7 18 5 33 0
3
1
*/
