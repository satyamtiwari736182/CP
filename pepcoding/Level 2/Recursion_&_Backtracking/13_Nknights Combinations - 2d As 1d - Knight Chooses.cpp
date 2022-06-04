// 1. You are given a number n, representing the size of a n * n chess board.
// 2. You are required to calculate and print the combinations in which n knights can be placed on the 
//      n * n chess-board. 
// 3. No knight shall be able to kill another.

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't 
//                force you but the intention is to teach a concept. Play in spirit of the question.


#include "../header.h"
int board[100][100]; // flag => to check empty position

bool isKnightSafe(int cell, int length)
{
    int row = cell / length, col = cell % length;
    int dirs[][4] = {{-1, -2, -2, -1},
                     {-2, -1, 1, 2}};

    for (int i = 0; i < 4; i++)
    {
        int row_dash = row + dirs[0][i], col_dash = col + dirs[1][i];
        if (board[row_dash][col_dash] == true)
            return false;
    }

    return true;
}

void queenPermutation(int qpsf, int total_queen, int lpq_cno)
// lpq_cno => previously placed cell no.
{
    if (qpsf == total_queen)
    {
        for (int row = 0; row < total_queen; row++)
        {
            for (int col = 0; col < total_queen; col++)
            {
                if (board[row][col] == true)
                    cout << "K ";
                else
                    cout << "_ ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int cell = lpq_cno + 1; cell < total_queen * total_queen; cell++)
    {
        int row = cell / total_queen, col = cell % total_queen;
        if (isKnightSafe(cell, total_queen) == true)
        {
            board[row][col] = true;
            queenPermutation(qpsf + 1, total_queen, cell);
            board[row][col] = false;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    Fill(board, 0);
    queenPermutation(0, n, -1);
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
// 2