// 1. You are given a number x.
// 2. You are given another number n.
// 3. You are required to calculate x raised to the power n. Don't change the signature of power function.

#include "../header.h"

int powLog(int x, int n)
{
    if (n == 0)
        return 1;
    int p = n & 1 ? x : 1;
    int res = powLog(x, n / 2);
    return p * res * res;
}

int main()
{
    cout << "hello!" << endl;
    cout << powLog(2, 10);
    return 0;
}

// 2 5