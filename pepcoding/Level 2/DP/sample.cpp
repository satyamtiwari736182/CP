
#include "../header.h"

int solution(vi &arr, int x, int y)
{
    int n = arr.size(), sum = 0;
    vi dp1(n), dp2(n); // dp1 => left prefix sum array and dp2 is for right;

    for (int i = 0; i < n; i++)
    {
        if (i < x)
            sum += arr[i], dp1[i] = sum;
        else
            sum += arr[i] - arr[i - x], dp1[i] = max(dp1[i + 1], sum);
    }

    sum = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (i + y >= n)
            sum += arr[i], dp2[i] = sum;
        else
            sum += arr[i] - arr[i + y], dp2[i] = max(dp2[i + 1], sum);
    }

    int ans = 0;
    for (int i = x - 1; i < n - y; i++)
        ans = max(ans, dp1[i] + dp2[i + 1]);

    //******************************************************************

    vi temp(n);
    dp1 = temp, dp2 = temp;
    // memset(&dp1, 0, sizeof(dp1));
    // memset(&dp2[0], 0, sizeof(dp2));
    // parr(dp1, n);

    sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < y)
            sum += arr[i], dp1[i] = sum;
        else
            sum += arr[i] - arr[i - y], dp1[i] = max(dp1[i + 1], sum);
    }

    sum = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (i + x >= n)
            sum += arr[i], dp2[i] = sum;
        else
            sum += arr[i] - arr[i + x], dp2[i] = max(dp2[i + 1], sum);
    }

    for (int i = y - 1; i < n - x; i++)
        ans = max(ans, dp1[i] + dp2[i + 1]);

    // cout << endl;
    return ans;
}

int main()
{
    cout << "\nHello world!\n";
    int n, x, y;
    cin >> n;
    vi arr(n);
    rarr(arr, 0, n);
    cin >> x >> y;
    cout << "\n==========\n";
    //------------------------------------------------------
    cout << solution(arr, x, y) << endl;
    return 0;
}

/*
9
0 6 5 2 2 5 1 9 4
1
2
*/
