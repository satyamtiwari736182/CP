// 1. You are given a positive number N.
// 2. You have to find the minimum number of operations required to convert N into 1.
// 3. Operations allowed :
//      (i)  If n is even, you have to replace n with n/2.
//      (ii) If n is odd, you can replace n with either n-1 or n+1.



#include "../header.h"

int solve(int n)
{
    int cnt = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else if (n == 3)
            n -= 1;
        else if (n % 4 == 1)
            n -= 1;
        else if (n % 4 == 3)
            n += 1;
        cnt++;
    }
    return cnt;
}

int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;

    cout << "\n========================================\n";
    cout << solve(n);
    cout << "\n========================================\n";

    return 0;
}

// 8
// 15