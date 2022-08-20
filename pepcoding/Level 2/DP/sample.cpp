#include "../header.h"

int *catalanNumber(int n)
{
    int *catlan = new int[n + 1];
    catlan[0] = catlan[1] = 1;
    for (int num = 2; num <= n; num++)
    {
        int sum = 0;
        for (int i = 0, j = num - 1; i < num; i++, j--)
            sum += catlan[i] * catlan[j];
        catlan[num] = sum;
    }
    return catlan;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    int *catlan = catalanNumber(n);
    parr(catlan, n + 1);
    //------------------------------------------------------

    return 0;
}

// 10

