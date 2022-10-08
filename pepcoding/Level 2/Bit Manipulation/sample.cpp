
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