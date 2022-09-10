// 1. You are given two arrays of integers arr1 and arr2.
// 2. You have to find the maximum length of subarray that appears in both the given arrays.

#include "../header.h"

int solution(vi &arr1, vi &arr2)
{
    const int n = arr1.size(), m = arr2.size();
    int dp[100][100];
    fill(&dp[0][0], &dp[99][99], 0);
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr1[i - 1] == arr2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    vi arr1(n);
    rarr(arr1, 0, n);
    cin >> n;
    vi arr2(n);
    rarr(arr2, 0, n);

    cout << "\n------------\n";
    cout << solution(arr1, arr2) << endl;
    //------------------------------------------------------

    return 0;
}

/*
5
5 4 3 2 1
6
7 8 4 3 2 5
*/
