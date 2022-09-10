// 1. You are given a N*N chessboard and the starting position of the knight in the chessboard.
// 2. The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).
// 3. You have to find the probability of knight to remain in the chessboard after exactly k number of moves.

// Note -> The knight continues moving until it has made exactly K moves or has moved off the chessboard.

#include "../header.h"

bool isValid(int ni, int nj, int n)
{
    if (ni >= 0 && nj >= 0 && ni < n && nj < n)
        return true;
    else
        return false;
}

double solution(int r, int c, int n, int k)
{
    vector<vector<double>> curr(n, vector<double>(n)), next(n, vector<double>(n));
    // double curr[N][N], next[N][N];
    // fill(&curr[0][0], &curr[N - 1][N - 1] + 1, 0);
    // fill(&next[0][0], &next[N - 1][N - 1] + 1, 0);

    curr[r][c] = 1;
    for (int m = 1; m <= k; m++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if (curr[i][j] != 0)
                {
                    int ni = 0, nj = 0;

                    ni = i + 2, nj = j + 1;
                    if (isValid(ni, nj, n) == true)
                        next[i][j] += curr[i][j] / 8.0;

                    ni = i + 2, nj = j - 1;
                    if (isValid(ni, nj, n) == true)
                        next[i][j] += curr[i][j] / 8.0;

                    ni = i - 2, nj = j + 1;
                    if (isValid(ni, nj, n) == true)
                        next[i][j] += curr[i][j] / 8.0;

                    ni = i - 2, nj = j - 1;
                    if (isValid(ni, nj, n) == true)
                        next[i][j] += curr[i][j] / 8.0;

                    ni = i + 1, nj = j + 2;
                    if (isValid(ni, nj, n) == true)
                        next[i][j] += curr[i][j] / 8.0;

                    ni = i + 1, nj = j - 2;
                    if (isValid(ni, nj, n) == true)
                        next[i][j] += curr[i][j] / 8.0;

                    ni = i - 1, nj = j + 2;
                    if (isValid(ni, nj, n) == true)
                        next[i][j] += curr[i][j] / 8.0;

                    ni = i - 1, nj = j - 2;
                    if (isValid(ni, nj, n) == true)
                        next[i][j] += curr[i][j] / 8.0;
                }
        }
        curr = next;
        fill(&next[0][0], &next[n - 1][n - 1] + 1, 0);
    }

    double sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            sum += curr[i][j];
    return sum;
}

int main()
{
    cout << "\nHello world!\n";
    int r, c, n, k;
    cin >> n >> k >> r >> c;
    cout << "\n==========\n";
    //------------------------------------------------------
    cout << solution(r, c, n, k) << endl;
    return 0;
}

/*
3 2 0 0
*/
