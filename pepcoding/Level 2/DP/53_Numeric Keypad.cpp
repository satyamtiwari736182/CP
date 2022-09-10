// 1. You are given a number N, which represents the count of buttons pressed on a mobile numeric keypad.
// 2. You can only press buttons that are up, left, right, down to the current button and the current button also.
// 3. You can not press bottom row corner buttons(* and #).

#include "../header.h"

int solution(int n)
{
    vvi dp(n + 1, vi(10));
    vvi data = {{0, 8}, {1, 2, 4}, {1, 2, 3, 5}, {2, 3, 6}, {1, 4, 5, 7}, {2, 4, 5, 6, 8}, {3, 5, 6, 9}, {4, 7, 8}, {5, 7, 8, 9, 0}, {6, 8, 9}};

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= 9; j++)
        {
            if (i == 1)
                dp[i][j] = 1;
            else
                for (int prev : data[j])
                    dp[i][j] += dp[i - 1][prev];
        }

    int sum = 0;
    for (int i = 0; i <= 9; i++)
        sum += dp[n][i];

    return sum;
}

int main()
{
    cout << "\nHello world!\n";
    int n;
    cin >> n;
    cout << "\n==========\n";
    //------------------------------------------------------
    cout << solution(n) << endl;
    return 0;
}

/*
2
*/
