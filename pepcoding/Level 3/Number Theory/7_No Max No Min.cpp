// You have an array with n elements. you have to create all subsequences of this array with length K. For each subsequence, you have to write down the product of k-2 integers, all elements of this sequence except the minimum and maximum element.
// your work will be considered done if you will be able to write down all these numbers and tell PepBoss their product mod 10^9+7.

#include "../header.h"

auto ncr_func(int n, int r)
{
    static int ncr[N + 1][N + 1];
    fill(&ncr[0][0], &ncr[0][0] + sizeof(ncr) / sizeof(ncr[0][0]), 0);

    for (int i = 0; i <= n; i++)
        ncr[i][0] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 1; j <= i && j < r; j++)
        {
            if (i == 1 && j == 1)
                ncr[i][j] = 1;
            else
                ncr[i][j] = ((ncr[i - 1][j] + ncr[i - 1][j - 1]) % mod);
        }
    return ncr;
}

int main()
{
    cout << "\nHello world!" << endl;
    auto ncr = ncr_func(50, 50);
    int t = 1;
    cin >> t;
    test(t)
    {
        int n, k;
        cin >> n >> k;
        vi arr;
        rvarr(arr, 0, n);
        cout << "\n============================================\n"
             << endl;
        // solution
        ll count[INF];
        memset(count, 0, sizeof(count));
        sort(all(arr));
        ll total = ncr[n - 1][k - 1];
        for (int i = 1; i <= n / 2; i++)
        {
            int mincount = 0, maxcount = 0;
            if (i >= k - 1)
                maxcount = ncr[i][k - 1];
            if (n - 1 - i >= k - 1)
                mincount = ncr[n - i - 1][k - 1];

            ll validcount = (total - mincount - maxcount + (mod - 1)) % (mod - 1);

            count[i] = validcount;
            count[n - 1 - i] = validcount;
        }
        ll ans = 1;
        for (int i = 1; i < n - 1; i++)
        {
            ll powi = pow(arr[i], count[i]);
            ans = (ans * powi) % mod;
        }

        cout << ans;
        cout << "\n============================================\n"
             << endl;
    }

    return 0;
}

// 1

// 4 3
// 1 2 3 4