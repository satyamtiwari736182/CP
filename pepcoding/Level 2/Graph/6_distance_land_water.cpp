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

class Pair1
{
public:
    int x, y;
    Pair1(int x1, int y1) : x(x1), y(y1) {}
};

void nearest_one_from_zero(vector<vi> &grid)
{
    int dirs[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    queue<Pair1 *> que;

    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j] == 1)
                que.push(new Pair1(i, j));

    int distance = 0;
    while (!que.empty())
    {
        int size = que.size();
        distance++;
        while (size--)
        {
            Pair1 *rem = que.front();
            que.pop();
            for (int i = 0; i < 4; i++)
            {
                int rowdash = rem->x + dirs[i][0];
                int coldash = rem->y + dirs[i][1];

                if (rowdash >= 0 && coldash >= 0 && rowdash < grid.size() && coldash < grid[0].size() && grid[rowdash][coldash] == 0)
                {
                    grid[rowdash][coldash] = distance;
                    que.push(new Pair1(rowdash, coldash));
                }
            }
        }
    }
}

int main()
{
    cout << "\nhello!" << endl;

    int n, m;
    cin >> n >> m;
    vector<vi> grid;
    rvmatrix(grid, n, m);
    cout << "\n--------------------------\n";
    nearest_one_from_zero(grid);
    pmatrix(grid, n, m);

    return 0;
}

// 5 5
// 1 0 0 0 1
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 1 0 0 0 1
