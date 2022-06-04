// https://codeforces.com/problemset/problem/1534/D

#include "../header.h"

void solve()
{
    int n;
    cin >> n;
    int adjMatrix[n + 1][n + 1], arr[n];
    Fill(adjMatrix, 0);
    cout << "? " << 1 << endl;
    fflush(stdout);
    rarr(arr, 0, n);

    int odd = 0, even = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            adjMatrix[1][i + 1] = 1;
            adjMatrix[i + 1][1] = 1;
        }
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    int check = -1;
    if (even <= odd)
        check = 0;
    else
        check = 1;

    for (int i = 2; i <= n; i++)
    {
        if (arr[i - 1] % 2 == check)
        {
            int arr2[n];
            cout << "? " << i << endl;
            fflush(stdout);
            rarr(arr2, 0, n);

            for (int j = 0; j < n; j++)
                if (arr2[j] == 1)
                {
                    adjMatrix[i][j + 1] = 1;
                    adjMatrix[j + 1][i] = 1;
                }
        }
    }

    cout << "!\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (adjMatrix[i][j] == 1)
            {
                cout << i << " " << j << endl;
                adjMatrix[j][i] = 0;
            }
        }
    }
}

int main()
{
    // cout << "\nHello world!" << endl;
    int t = 1;
    // cin >> t;
    test(t)
    {
        solve();
    }

    return 0;
}