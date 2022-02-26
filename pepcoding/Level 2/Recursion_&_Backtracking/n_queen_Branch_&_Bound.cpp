
#include <bits/stdc++.h>
using namespace std;

#define REP(a, b) for (int i = a; i <= b; i++)
#define REP2(i, a, b) for (i = a; i <= b; i++)

#define rarr(arr, l, r)         \
    for (int i = l; i < r; i++) \
        cin >> arr[i];

#define rvarr(arr, l, r)        \
    for (int i = l; i < r; i++) \
    {                           \
        int val;                \
        cin >> val;             \
        arr.push_back(val);     \
    }

#define parr(arr, n)            \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";

#define rmatrix(arr, n, m)          \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
            cin >> arr[i][j];

#define rvmatrix(arr, n, m)         \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
        {                           \
            int val;                \
            cin >> val;             \
            arr[i].push_back(val);  \
        }

#define pmatrix(arr, n, m)            \
    for (int i = 0; i < n; i++)       \
    {                                 \
        for (int j = 0; j < m; j++)   \
            cout << arr[i][j] << " "; \
        cout << endl;                 \
    }

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

// Solvin n-queen problem
void solve(vector<vi> &board, int row, vi &cols, vi &forward_diag, vi &backward_diag, string asf)
{

    if (row == board.size())
    {
        cout << asf << "\t";
        return;
    }

    for (int col = 0; col < board[0].size(); col++)
    {

        // Branch and Bound approach.  Here we are bounding the possible branches of recursion for placin the queen
        if (!cols[col] && !forward_diag[row + col] && !backward_diag[row - col + board.size() - 1])
        {
            board[row][col] = true;
            cols[col] = true;
            forward_diag[row + col] = true;
            backward_diag[row - col + board.size() - 1] = true;
            solve(board, row + 1, cols, forward_diag, backward_diag, asf + to_string(row) + "-" + to_string(col) + ", ");

            // backtracking
            board[row][col] = false;
            cols[col] = false;
            forward_diag[row + col] = false;
            backward_diag[row - col + board.size() - 1] = false;
        }
    }
}

int main()
{
    cout << "\nHello world!" << endl;
    int n;
    cin >> n;
    vector<vi> board;

    board.resize(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i].resize(n);

    vi cols(n);
    vi forward_diag(2 * n - 1);
    vi backward_diag(2 * n - 1);

    cout << "\n====================================\n";
    solve(board, 0, cols, forward_diag, backward_diag, "");
    cout << "\n====================================\n";

    return 0;
}