// 1. You are give a partially filled 9*9 2-D array(arr) which represents an incomplete sudoku state.
// 2. You are required to assign the digits from 1 to 9 to the empty cells following some rules.
// Rule 1 -> Digits from 1-9 must occur exactly once in each row.
// Rule 2 -> Digits from 1-9 must occur exactly once in each column.
// Rule 3 -> Digits from 1-9 must occur exactly once in each 3x3 sub-array of the given 2D array.

// Assumption -> The given Sudoku puzzle will have a single unique solution.
// Note -> You have to Solve this problem using bits.



#include "../header.h"

void soleSudoku(vector<vi> &board, vi &rows, vi &cols, vector<vi> &grid, int i, int j)
{
    if (i == board.size())
    {
        pmatrix(board, 9, 9);
        return;
    }

    if (board[i][j] > 0)
    {
        int ni = j == board[0].size() - 1 ? i + 1 : i;
        int nj = j == board[0].size() - 1 ? 0 : j + 1;

        soleSudoku(board, rows, cols, grid, ni, nj);
    }

    else
    {
        for (int num = 1; num <= 9; num++)
        {
            if ((rows[i] & (1 << num)) == 0 &&
                (cols[j] & (1 << num)) == 0 &&
                (grid[i / 3][j / 3] & (1 << num)) == 0)
            {
                board[i][j] = num;
                rows[i] ^= (1 << num);
                cols[j] ^= (1 << num);
                grid[i / 3][j / 3] ^= (1 << num);
                // soleSudoku(board, rows, cols, grid, j == board[0].size() - 1 ? i + 1 : i, j == board[0].size() - 1 ? 0 : j + 1);
                int ni = j == board[0].size() - 1 ? i + 1 : i;
                int nj = j == board[0].size() - 1 ? 0 : j + 1;

                soleSudoku(board, rows, cols, grid, ni, nj);

                // backtracking
                board[i][j] = 0;
                rows[i] ^= (1 << num);
                cols[j] ^= (1 << num);
                grid[i / 3][j / 3] ^= (1 << num);
            }
        }
    }
}

int main()
{
    cout << "\nHello world!" << endl;

    vector<vi> board, grid;

    vi rows, cols;

    rows.resize(9);
    cols.resize(9);
    grid.resize(3);
    board.resize(9);

    for (auto &grd : grid)
        grd.resize(3);
    for (auto &row : board)
        row.resize(9);

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            int digit;
            cin >> digit;
            board[i][j] = digit;
            rows[i] |= (1 << digit);
            cols[j] |= (1 << digit);
            grid[i / 3][j / 3] |= (1 << digit);
        }

    cout << "\n========================================\n";
    soleSudoku(board, rows, cols, grid, 0, 0);
    // pmatrix(board, 9, 9);
    // parr(rows, 9);
    cout << "\n========================================\n";
    return 0;
}

// 3 0 6 5 0 8 4 0 0
// 5 2 0 0 0 0 0 0 0
// 0 8 7 0 0 0 0 3 1
// 0 0 3 0 1 0 0 8 0
// 9 0 0 8 6 3 0 0 5
// 0 5 0 0 9 0 6 0 0
// 1 3 0 0 0 0 2 5 0
// 0 0 0 0 0 0 0 7 4
// 0 0 5 2 0 6 3 0 0