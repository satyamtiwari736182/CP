
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
            mat[i].push_back(val);  \
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

int findParent(int *parent, int x)
{
    if (parent[x] == x)
        return x;
    int temp = findParent(parent, parent[x]);
    parent[x] = temp;
    return temp;
}

bool Union(int *rank, int *parent, int x, int y)
{
    int px = findParent(parent, x);
    int py = findParent(parent, y);

    if (px != py)
    {
        if (rank[px] > rank[py])
            parent[py] = px;
        else if (rank[px] < rank[py])
            parent[px] = py;
        else
        {
            parent[px] = py;
            rank[py]++;
        }
        return true;
    }
    return false;
}

int num_of_island_II(int m, int n, vector<vi> &position)
{
    vi ans;
    int dirs[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int parent[m * n];
    int rank[m * n];

    fill(rank, rank + m * n, 0);
    fill(parent, parent + m * n, -1);

    int count = 0;

    for (int i = 0; i < position.size(); i++)
    {
        int row = position[i][0];
        int col = position[i][1];

        int cell_num = row * n + col;

        if (parent[cell_num] != -1)
        {
            ans.push_back(count);
            continue;
        }

        parent[cell_num] = cell_num;
        rank[cell_num] = 1;
        count++;

        for (auto dir : dirs)
        {
            int rowdash = row + dir[0];
            int coldash = col + dir[1];
            int celldash = rowdash * n + coldash;

            if (rowdash < 0 || coldash < 0 || rowdash >= m || coldash >= n || parent[celldash] == -1)
                continue;

            bool merged = Union(rank, parent, cell_num, celldash);
            if (merged)
                count--;
        }
        ans.pb(count);
    }

    for (int i : ans)
        cout << i << " ";
    return 0;
}

int main()
{
    cout << "\nHello world!" << endl;

    int n, m, q;
    cin >> n >> m >> q;
    vector<vi> pos;
    pos.resize(q);

    for (int i = 0; i < q; i++)
    {
        int row, col;
        cin >> row >> col;
        pos[i].push_back(row);
        pos[i].push_back(col);
    }

    cout << "\n==========================================\n";
    num_of_island_II(n, m, pos);
    cout << "\n==========================================\n";
    return 0;
}

/*
3 5 7
0 3
1 2
0 2
1 4
2 3
1 3
1 2

*/