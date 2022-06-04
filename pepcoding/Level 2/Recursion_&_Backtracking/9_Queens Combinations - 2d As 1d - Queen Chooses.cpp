// 1. You are given a number n, representing the size of a n * n chess board.
// 2. You are required to calculate and print the combinations in which n queens can be placed on the 
//      n * n chess-board. 

// Note -> Use the code snippet and follow the algorithm discussed in question video. The judge can't 
//                force you but the intention is to teach a concept. Play in spirit of the question.

#include "../header.h"
int board[100][100]; // flag => to check empty position
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
                    cout << "q ";
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
        board[row][col] = true;
        queenPermutation(qpsf + 1, total_queen, cell);
        board[row][col] = false;
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