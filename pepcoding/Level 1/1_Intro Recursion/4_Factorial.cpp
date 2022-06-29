// 1. You are given a number n.
// 2. You are required to calculate the factorial of the number. Don't change the signature of factorial function.
#include "../header.h"

int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return fact(n - 1) * n;
}

int main()
{
    cout << "hello!" << endl;
    cout << fact(6);

    return 0;
}
// 5