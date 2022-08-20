#include "../header.h"

class Pair
{
public:
    int i, j;
    string coins;
    Pair(int ii, int jj, string ccoins)
    {
        i = ii;
        j = jj;
        coins = ccoins;
    }
};

int main()
{
    int n, tar;
    cin >> n;
    int arr[n + 1] = {0};
    rarr(arr, 1, n + 1);
    cin >> tar;
    int dp[n + 1][tar + 1];
    fill(*dp, *dp + (tar + 1) * (n + 1), 0);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= tar; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else
            {
                if (arr[i] > j)
                    dp[i][j] = dp[i - 1][j];
                else if (arr[i] == j)
                    dp[i][j] = 1;
                else
                {
                    int rem = j - arr[i];
                    if (dp[i - 1][rem])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }

    cout << "\n****************\n"
         << dp[n][tar] << endl;

    queue<Pair> que;
    if (dp[n][tar])
        que.push(Pair(n, tar, ""));
    while (!que.empty())
    {
        Pair temp = que.front();
        if (temp.j == 0)
            cout << temp.coins << "." << endl;
        else
        {
            if (dp[temp.i - 1][temp.j] == 1)
                que.push(Pair(temp.i - 1, temp.j, "" + temp.coins));
            if (dp[temp.i - 1][temp.j - arr[temp.i]] == 1)
                que.push(Pair(temp.i - 1, temp.j - arr[temp.i], to_string(arr[temp.i]) + " " + temp.coins));
        }
        que.pop();
    }

    cout << "\n******************\n";
    pmatrix(dp, n + 1, tar + 1);

    return 0;
}

// 5
// 4 2 7 1 3
// 10
