// https://www.spoj.com/problems/LCA/


#include "../header.h"

vector<vi> childs;
vi travel; // Linear tree
vi depth, start;
int table[N][N]; // sparse table

void dfs(int node)
{
    start[node] = travel.size();
    travel.pb(node);

    for (int chld : childs[node])
    {
        depth[chld] = 1 + depth[node];
        dfs(chld);
        travel.pb(node);
    }
}

void buildTable()
{
    memset(table, 0, sizeof(table));
    int maxBit = 0;                        // log2(travel.size());
    while ((1 << maxBit) <= travel.size()) // alternate ways
        maxBit++;
    maxBit--;

    for (int i = 0; i < travel.size(); i++)
        table[0][i] = travel[i];

    for (int j = 1; j <= maxBit; j++)
    {
        for (int i = 0; i + (1 << j) <= travel.size(); i++)
        {
            int v = table[j - 1][i];
            int u = table[j - 1][i + (1 << (j - 1))];
            table[j][i] = depth[v] < depth[u] ? v : u;
        }
    }
}

int rangeMin(int left, int right)
{
    int count = right - left + 1;
    int k = log2(count);
    int v = table[k][left]; /// l-------(l+2^k)
    int u = table[k][right - (1 << k) + 1];
    return depth[v] < depth[u] ? v : u;
}

void solve()
{
    int n;
    cin >> n;
    depth.resize(n + 1);
    start.resize(n + 1);
    childs.resize(n + 1);

    // building input tree
    for (int i = 1; i <= n; i++)
    {
        int cnt_child;
        cin >> cnt_child;
        for (int j = 0; j < cnt_child; j++)
        {
            int chld;
            cin >> chld;
            childs[i].pb(chld);
        }
    }

    // tree flattening  -using-  Eular Tour
    dfs(1);
    depth[0] = INT_MAX;
    // build sparse table
    buildTable();
    // Query data
    int q, ans = 0;
    cin >> q;
    test(q)
    {
        int u, v;
        cin >> u >> v;
        ans = rangeMin(min(start[u], start[v]), max(start[u], start[v]));
        cout << ans << "  **\n";
    }
}

int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    cin >> t;
    test(t)
    {
        solve();

        cout << "\n------------------------------\n";
        // pmatrix(table, 10, 10);
        parr(travel, travel.size());
    }

    return 0;
}

// 1
// 7
// 3 2 3 4
// 0
// 3 5 6 7
// 0
// 0
// 0
// 0
// 2
// 5 7
// 2 7