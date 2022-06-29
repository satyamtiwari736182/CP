// 1. You are given a number x.
// 2. You are given another number n.
// 3. You are required to calculate x raised to the power n. Don't change the signature of power function .

#include "../header.h"

int powLinear(int x, int n)
{
    if (n == 0)
        return 1;
    return x * powLinear(x, n - 1);
}

int main()
{
    cout << "hello!" << endl;
    cout << powLinear(2, 10);

    return 0;
}

// 2 5