#include "../header.h"

class Pair
{
public:
    int i, lent;
    string psf;
    Pair(int i, int lent, string psf)
    {
        this->i = i;
        this->lent = lent;
        this->psf = psf;
    }
};

int main()
{
    int n;
    cin >> n;

    int arr[100], dp[100], lent = 1, pos = 0;
    fill(dp, dp + n, 0);
    rarr(arr, 0, n);
    dp[0] = 1;

    //------------------------------------------------------
    for (int i = 1; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < i; j++)
            if (arr[i] >= arr[j])
                count = max(count, dp[j]);
        dp[i] = count + 1;

        if (dp[i] > lent)
        {
            lent = dp[i];
            pos = i;
        }
    }
    //------------------------------------------------------
    cout << "\n"
         << lent << endl;
    queue<Pair> que;
    que.push(Pair(pos, lent, to_string(arr[pos])));
    while (!que.empty())
    {
        Pair temp = que.front();
        if (temp.lent == 1)
            cout << temp.psf << "." << endl;
        for (int i = temp.i; i >= 0; i--)
            if (dp[i] == temp.lent - 1 && arr[i] <= arr[temp.i])
                que.push(Pair(i, temp.lent - 1, to_string(arr[i]) + " -> " + temp.psf));
        que.pop();
    }

    cout << "\nHello world!\n";

    return 0;
}

// 10
// 10 22 9 33 21 50 41 60 80 1
