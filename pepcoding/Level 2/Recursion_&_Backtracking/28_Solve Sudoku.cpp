// 1. You are give a partially filled 9*9 2-D array(arr) which represents an incomplete sudoku state.
// 2. You are required to assign the digits from 1 to 9 to the empty cells following some rules.
// Rule 1 -> Digits from 1-9 must occur exactly once in each row.
// Rule 2 -> Digits from 1-9 must occur exactly once in each column.
// Rule 3 -> Digits from 1-9 must occur exactly once in each 3x3 sub-array of the given 2D array.

// Assumption -> The given Sudoku puzzle will have a single unique solution.

#include "../header.h"

bool isValid(int board[9][9], int x, int y, int val)
{
    for (int j = 0; j < 9; j++)
        if (board[x][j] == val)
            return false;

    for (int i = 0; i < 9; i++)
        if (board[i][y] == val)
            return false;

    int smi = x / 3 * 3;
    int smj = y / 3 * 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[smi + i][smj + j] == val)
                return false;

    return true;
}

void solveSudoku(int board[9][9], int i, int j)
{
    if (i == 9)
    {
        pmatrix(board, 9, 9);
        return;
    }
    int row = 0, col = 0;
    if (j == 8)
    {
        row = i + 1;
        col = 0;
    }
    else
    {
        row = i;
        col = j + 1;
    }

    if (board[i][j] != 0)
        solveSudoku(board, row, col);
    else
    {
        for (int po = 1; po <= 9; po++)
        {
            if (isValid(board, i, j, po) == true)
            {
                board[i][j] = po;
                solveSudoku(board, row, col);
                board[i][j] = 0;
            }
        }
    }
}

void solve()
{
    int arr[9][9];
    rmatrix(arr, 9, 9);
    cout << endl;
    solveSudoku(arr, 0, 0);
    // pmatrix(arr, 9, 9);
}

int main()
{
    cout << "\nHello world\n";
    int t = 1;
    // cin >> t;
    test(t)
        solve();

    return 0;
}
/*
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
*/