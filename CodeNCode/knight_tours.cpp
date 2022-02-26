#include <bits/stdc++.h>
using namespace std;
#define REP(a, b) for (int i = a; i <= b; i++)
#define REP2(i, a, b) for (i = a; i <= b; i++)
#define print(arr, l, r)         \
    for (int i = l; i <= r; i++) \
        cout << arr[i] << " ";
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define ll long long
#define fs first
#define se second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define mod 1000000007
const int INF = 1e9 + 7;
const double PI = 3.141592653589793238;
const int M = 100, N = 100;
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
