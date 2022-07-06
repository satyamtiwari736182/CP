// 1. You are given a number n, the size of a chess board.
// 2. You are given a row and a column, as a starting point for a knight piece.
// 3. You are required to generate the all moves of a knight starting in (row, col) such that knight visits
//      all cells of the board exactly once.
// 4. Complete the body of printKnightsTour function - without changing signature - to calculate and
//      print all configurations of the chess board representing the route
//      of knight through the chess board. Use sample input and output to get more idea.

#include "../header.h"
void display(int arr[N][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << "------------" << endl;
}
void knightTour(int board[N][N], int n, int row, int col, int mov)
{
    if (row >= n || col >= n || row < 0 || col < 0 || board[row][col])
        return;

    if (mov == n * n)
    {
        board[row][col] = mov;
        display(board, n);
        board[row][col] = 0;
        return;
    }

    board[row][col] = mov;

    knightTour(board, n, row - 2, col + 1, mov + 1);
    knightTour(board, n, row - 1, col + 2, mov + 1);
    knightTour(board, n, row + 1, col + 2, mov + 1);
    knightTour(board, n, row + 2, col + 1, mov + 1);

    knightTour(board, n, row + 2, col - 1, mov + 1);
    knightTour(board, n, row + 1, col - 2, mov + 1);
    knightTour(board, n, row - 1, col - 2, mov + 1);
    knightTour(board, n, row - 2, col - 1, mov + 1);

    board[row][col] = 0;
}
int main()
{
    cout << "hello" << endl;
    int n, ir, ic;
    cin >> n >> ir >> ic;
    int arr[N][N];
    memset(arr, 0, sizeof(arr));
    knightTour(arr, n, ir, ic, 1);

    cout << "hello!" << endl;
    return 0;
}

// 5
// 2
// 0