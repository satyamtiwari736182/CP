#include "../header.h"
int main()
{
    int n;
    cin >> n;
    int arr[N], dp[N];
    arr[0] = 0;
    rarr(arr, 1, n + 1);

    for (int i = 0; i < n + 1; i++)
        dp[i] = arr[i];

    //-----------------------------------------------------
    for (int i = 1; i < n + 1; i++)
        for (int j = 0; j <= i / 2; j++)
            dp[i] = max(dp[i], dp[i - j] + dp[j]);
    //-----------------------------------------------------

    cout << "\nHello world!\n";
    parr(arr, n + 1);
    cout << "\n*******************************\n";
    parr(dp, n + 1);

    return 0;
}

// 8
// 1 5 8 9 10 17 17 20
