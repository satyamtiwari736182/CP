// 1. You are given a positive number n.
// 2. You are required to print the counting from n to 1.
// 3. You are required to not use any loops. Complete the body of print Decreasing function to achieve it.

#include "../header.h"

void printDeceresing(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    printDeceresing(n - 1);
    cout << n << " ";
}

int main()
{
    cout << "hello!" << endl;
    printDeceresing(10);

    return 0;
}

// 5
// 4
// 3
// 2
// 1