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

// int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
string psf;

void dfs(vector<vi> &grid, int row, int col)
{
    grid[row][col] = 0;
    if (col + 1 < grid[0].size() && grid[row][col + 1])
    {
        psf += "r";
        dfs(grid, row, col + 1);
    }
    if (col - 1 > 0 && grid[row][col - 1])
    {
        psf += "l";
        dfs(grid, row, col - 1);
    }
    if (row + 1 < grid.size() && grid[row + 1][col])
    {
        psf += "u";
        dfs(grid, row + 1, col);
    }
    if (row - 1 > 0 && grid[row - 1][col])
    {
        psf += "d";
        dfs(grid, row - 1, col);
    }
    psf += "z";
}

int num_of_distinct_island(vector<vi> &grid)
{
    int count = 0;
    set<string> hashset;
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j])
            {
                psf = "x";
                dfs(grid, i, j);
                hashset.insert(psf);
            }
    count = hashset.size();
    return count;
}
int main()
{
    cout << "\nhello!" << endl;

    int n, m;
    cin >> n >> m;
    vector<vi> grid;
    rvmatrix(grid, n, m);
    cout << "\n--------------------------\n";
    cout << num_of_distinct_island(grid) << endl;
    pmatrix(grid, n, m);

    return 0;
}

// 5 5
// 0 0 0 1 0
// 0 1 1 0 0
// 0 1 0 1 1
// 0 0 0 0 1
// 0 1 1 0 0