// 1. Pepcoder arranged some glasses in the form of pascal triangle.
// 2. Capacity of each glass is 1 litre. If you pour K amount of water in a glass, it will retain 1 litre and
//    rest of it gets equally distributed in left bottom glass and right bottom glass.
// 3. If pepcoder pours K litres of water in the topmost glass, you have to find out the amount of water in Cth glass of Rth row.

// Assumption -> There are enough glasses in the triangle till no glass overflows.

#include "../header.h"

double solution(int amt, int row, int col)
{
    vector<vector<double>> dp(amt + 1, vector<double>(amt + 1));
    dp[0][0] = amt * 1;

    for (int i = 0; i < dp.size(); i++)
        for (int j = 0; j <= i; j++)
            if (dp[i][j] > 1)
            {
                double spare = dp[i][j] - 1;
                dp[i][j] = 1;
                dp[i + 1][j] += spare / 2;
                dp[i + 1][j + 1] += spare / 2;
            }

    // for (int i = 0; i < dp.size(); i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;
    return dp[row][col];
}

int main()
{
    cout << "\nHello world!\n";
    int k, r, c;
    cin >> k >> r >> c;

    cout << "\n------------\n";
    cout << solution(k, r, c) << endl;
    //------------------------------------------------------

    return 0;
}

/*
7 3 1
*/

// 3
// 1
// 0