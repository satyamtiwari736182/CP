// 1. Pepcoder is feeling confident after solving many problems on Bit Manipulation.
// 2. So, his teacher ask him to find out the count of positive integers strictly less than N, having same
//      number of set bits as that of N.
// 3. Let us see that if pepcoder can solve it or not.

#include "../header.h"

int csb(int n)
{
    int cnt = 0;

    while (n > 0)
        n -= n & -n, cnt++;

    return cnt;
}

int ncr(int n, int r)
{
    if (n < r)
        return 0;
    int res = 1;

    for (int i = 0; i < r; i++)
        res *= (n - i), res /= (i + 1);

    return res;
}

int solve(int n, int k, int idx)
{
    if (idx == 0)
        return 0;

    int res = 0;
    int mask = 1 << idx;

    if ((mask & n) == false)
        res += solve(n, k, idx - 1);
    else
        res += solve(n, k - 1, idx - 1) + ncr(idx, k); // solve(n, k, idx - 1);

    return res;
}

int main()
{
    cout << "hello world!\n";
    // cout << sizeof(ll);
    cout << "\n---------------\n";
    int n;
    cin >> n;
    int k = csb(n);

    cout << solve(n, k, 31) << endl;

    return 0;
}

// 1024