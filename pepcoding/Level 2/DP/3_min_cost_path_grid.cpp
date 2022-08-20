#include "../header.h"

class Pair
{
public:
    int i, j, cost;
    string path = "";
    Pair(int i, int j, int cost, string path)
    {
        this->i = i;
        this->j = j;
        this->cost = cost;
        this->path = path;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[100][100], dp[100][100];
    fill(*dp, *dp + (n + 1) * (m + 1), 0);

    rmatrix(arr, n, m);

    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == n - 1)
                dp[i][j] = dp[i][j + 1] + arr[i][j];
            else if (j == m - 1)
                dp[i][j] = dp[i + 1][j] + arr[i][j];
            else
                dp[i][j] = arr[i][j] + min(dp[i][j + 1], dp[i + 1][j]);
        }
    cout << "\n*******************\n"
         << dp[0][0] << endl;

    queue<Pair> que;
    que.push(Pair(0, 0, dp[0][0], ""));

    while (!que.empty())
    {
        Pair temp = que.front();
        que.pop();
        if (temp.i == n - 1 && temp.j == m - 1)

            cout << temp.path << "." << endl;

        else if (temp.i == n - 1)
            que.push(Pair(temp.i, temp.j + 1, dp[temp.i][temp.j + 1], temp.path + "H"));
        else if (temp.j == m - 1)
            que.push(Pair(temp.i + 1, temp.j, dp[temp.i + 1][temp.j], temp.path + "V"));
        else
        {
            int hCost = dp[temp.i][temp.j + 1];
            int vCost = dp[temp.i + 1][temp.j];

            if (vCost < hCost && temp.i + 1 < n)
                que.push(Pair(temp.i + 1, temp.j, vCost, temp.path + "v"));
            else if (hCost < vCost && temp.j + 1 < m)
                que.push(Pair(temp.i, temp.j + 1, hCost, temp.path + "h"));
            else
            {
                que.push(Pair(temp.i + 1, temp.j, vCost, temp.path + "v"));
                que.push(Pair(temp.i, temp.j + 1, hCost, temp.path + "h"));
            }
        }
    }
    cout << "\n*******************\n";
    pmatrix(dp, n, m);
    cout << "\nhello!\n";

    return 0;
}

// 6
// 6
// 0 1 4 2 8 2
// 4 3 6 5 0 4
// 1 2 4 1 4 6
// 2 0 7 3 2 2
// 3 1 5 9 2 4
// 2 7 0 8 5 1