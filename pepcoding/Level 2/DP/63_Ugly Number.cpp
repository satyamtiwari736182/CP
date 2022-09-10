// 1. You are given a number N.
// 2. You have to find Nth ugly number.
// 3. Ugly number is defined as the number whose prime factors are only 2,3 and 5.  
// 4. First eleven ugly numbers are -> 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15.

// Assumption -> 1 is the first ugly number.


#include "../header.h"

int solution(int n)
{
    int *dp = new int[n + 1];
    fill(dp, dp + n + 1, 0);

    dp[1] = 1;

    int p2 = 1, p3 = 1, p5 = 1;
    for (int i = 2; i <= n; i++)
    {
        int f1 = 2 * dp[p2];
        int f2 = 3 * dp[p3];
        int f3 = 5 * dp[p5];

        int minVal = min(f1, min(f2, f3));
        dp[i] = minVal;

        if (minVal == f1)
            p2++;
        if (minVal == f2)
            p3++;
        if (minVal == f3)
            p5++;
    }
    parr(dp, n + 1);
    cout << endl;
    return dp[n];
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;

    cout << "\n------------\n";
    cout << solution(n) << endl;

    //------------------------------------------------------

    return 0;
}

/*
20
*/
