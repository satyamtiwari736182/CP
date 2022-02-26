#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    int i, j, s;
    string psf;
    Pair(int i, int j, int s, string psf)
    {
        this->i = i;
        this->j = j;
        this->s = s;
        this->psf = psf;
    }
};

int main()
{
    int n;
    cin >> n;
    int arr[n], dp[n];

    fill(dp, dp + n, -1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //------------------------------------------
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
            dp[i] = 0;
        if (arr[i] > 0)
        {
            int val = INT_MAX;
            for (int j = 1; j <= arr[i]; j++)
            {
                if ((i + j) < n && dp[i + j] != -1)
                    val = min(dp[i + j], val);
            }
            dp[i] = val + 1;
        }
    }

    //----------------------------------------------

    queue<Pair> que;
    que.push(Pair(0, arr[0], dp[0], "0"));
    cout << dp[0] << endl;
    while (!que.empty())
    {
        Pair temp = que.front();
        if (temp.s == 0)
            cout << temp.psf << "." << endl;
        for (int i = 1; i <= temp.j; i++)
            if ((temp.i + i) < n && dp[temp.i + i] != -1 && dp[temp.i + i] == temp.s - 1)
                que.push(Pair(temp.i + i, arr[temp.i + i], dp[temp.i + i], temp.psf + " -> " + to_string(temp.i + i)));
        que.pop();
    }

    //----------------------------------------------
    // string psf = "0 -> ";
    // vector<string> totalPath;
    // while (p != n - 1)
    // {
    //     int path;
    //     for (int i = 1; i <= arr[p]; i++)
    //     {
    //         if ((p + i) < n && dp[p + i] != -1 && dp[p + i] < steps)
    //         {
    //             steps = dp[p + i];
    //             path = p + i;
    //         }
    //     }
    //     p = path;
    //     psf = psf + to_string(path) + " -> ";
    // }
    cout << "\n*********************\n"
         << endl;

    for (int i = 0; i < n; i++)
        cout << dp[i] << " ";

    return 0;
}

// 10
// 3 3 0 2 1 2 4 2 0 0

// 10
// 3 3 3 2 1 2 4 2 2 0
// 0 1 2 3 4 5 6 7 8 9