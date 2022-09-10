// 1. Given an integer n.
// 2. Return the number of ways you can write n as the sum of consecutive positive integers.

#include "../header.h"

int consecutiveNumberSum(int num)
{
    int cnt = 0;
    for (int k = 1; 2 * num > k * (k - 1); k++)
    {
        int numerator = num - (k * (k - 1) / 2);
        if (numerator % k == 0)
            cnt++;
    }
    return cnt;
}

void solve()
{
    int n;
    cin >> n;
    cout << "--------------------" << endl;
    cout << consecutiveNumberSum(n);
}

int main()
{
    cout << "\nHello world\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();

    return 0;
}

// 15