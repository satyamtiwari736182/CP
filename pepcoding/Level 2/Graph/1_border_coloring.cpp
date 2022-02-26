#include <bits/stdc++.h>
using namespace std;

#define REP(a, b) for (int i = a; i <= b; i++)
#define REP2(i, a, b) for (i = a; i <= b; i++)

#define rarr(arr, l, r)         \
    for (int i = l; i < r; i++) \
        cin >> arr[i];

#define parr(arr, n)            \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << " ";

#define rmatrix(arr, n, m)          \
    for (int i = 0; i < n; i++)     \
        for (int j = 0; j < m; j++) \
            cin >> arr[i][j];

#define rvmatrix(arr, n, m)         \
    for (int i = 0; i < n; i++)     \
    {                               \
        vi vec;                     \
        for (int j = 0; j < m; j++) \
        {                           \
            int x;                  \
            cin >> x;               \
            vec.pb(x);              \
        }                           \
        arr.pb(vec);                \
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

int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(vector<vi> &grid, int row, int col, int color)
{
    grid[row][col] = -color;
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        int rowdash = row + dirs[i][0];
        int coldash = col + dirs[i][1];

        if (rowdash < 0 || coldash < 0 || rowdash >= grid.size() || coldash >= grid[0].size() || abs(grid[rowdash][coldash]) != color)
            continue;

        count++;

        if (grid[rowdash][coldash] == color)
            dfs(grid, rowdash, coldash, color);
    }
    if (count == 4)
        grid[row][col] = color;
}

void border_coloring(vector<vi> &grid, int row, int col, int color)
{
    dfs(grid, row, col, grid[row][col]);

    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j] < 0)
                grid[i][j] = color;
}
int main()
{
    cout << "\nhello!" << endl;

    int n, m;
    cin >> n >> m;
    vector<vi> grid;
    rvmatrix(grid, n, m);
    border_coloring(grid, 1, 1, 9);
    cout << "\n--------------------------\n";
    pmatrix(grid, n, m);

    return 0;
}

// 5 5
// 2 3 4 3 1
// 4 2 2 2 1
// 1 2 2 2 1
// 5 2 2 2 1
// 6 7 0 1 1