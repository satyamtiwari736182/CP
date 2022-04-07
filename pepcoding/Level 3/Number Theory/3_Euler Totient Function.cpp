// you have been given a number n, count the number of integers between 1 to n inclusive, which are co-prime to n.

#include "../header.h"

int euler(int n)
{
    int count = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            count = count - count / i;
            while (n % i == 0)
                n = n / i;
        }
    }
    if (n > 1)
        count = count - count / n;
    return count;
}

int main()
{
    cout << "\nHello world!" << endl;
    int t;
    cin >> t;
    test(t)
    {
        int n;
        cin >> n;
        cout << euler(n) << endl;
    }

    return 0;
}

// 1
// 7