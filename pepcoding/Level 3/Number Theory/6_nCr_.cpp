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
    int t;
    // pmatrix(ncr, 10, 10);
    cin >> t;
    test(t)
    {
        int n, r;
        cin >> n >> r;
        cout << ncr[n][r] << endl;
    }

    return 0;
}