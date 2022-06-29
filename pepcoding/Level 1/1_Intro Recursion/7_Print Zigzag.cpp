// 1. Here are a few sets of inputs and outputs for your reference
// Input1 -> 1
// Output1 -> 1 1 1

// Input2 -> 2
// Output2 -> 2 1 1 1 2 1 1 1 2

// Input2 -> 3
// Output3 -> 3 2 1 1 1 2 1 1 1 2 3 2 1 1 1 2 1 1 1 2 3

// 2. Figure out the pattern and complete the recursive function pzz to achieve the above for any positive number n.

#include "../header.h"

void printZigZag(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    printZigZag(n - 1);
    cout << n << " ";
    printZigZag(n - 1);
    cout << n << " ";
}

int main()
{
    cout << "hello!" << endl;
    printZigZag(2);
    return 0;
}

// 3