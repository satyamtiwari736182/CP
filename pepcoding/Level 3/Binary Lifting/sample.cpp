#include "../header.h"

int maxRow = 0; // log2(n)
vector<vi> childs;
vi level, parent;
int table[N][N];

void getInputs(int n)
{
    childs.resize(n + 1);
    parent.resize(n + 1);
    level.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int chld_cnt = 0;
        cin >> chld_cnt;
        while (chld_cnt-- > 0)
        {
            int chd;
            cin >> chd;
            childs[i].pb(chd);
        }
    }
}

void dfs(int node)
{
    for (int chld : childs[node])
    {
        parent[chld] = node;
        level[chld] = level[node] + 1;
        dfs(chld);
    }
}

void buildSparceTable()
{
    memset(table, 0, sizeof(table));
    int n = childs.size();
    maxRow = log2(n);

    for (int i = 0; i < n; i++)
        table[0][i] = parent[i];

    for (int p = 1; p <= maxRow; p++)
        for (int i = 2; i < n; i++)
            table[p][i] = table[p - 1][table[p - 1][i]];
}

int lca(int u, int v)
{
    // making sure that, level[v]>level[u]
    if (level[u] > level[v])
        swap(u, v);

    // making level of 'u' and 'v' same.
    int k = level[v] - level[u];
    for (int i = maxRow; i >= 0; i--)
    {
        int mask = 1 << i;
        if ((mask & k) > 0)
            v = table[i][v];
    }

    if (u == v)
        return u;

    // jumping up the tree by ' 2^i ' { provided jump is valid }
    for (int i = maxRow; i >= 0; i--)
    {
        int up = table[i][u];
        int vp = table[i][v];
        if (up != vp)
        {
            u = up;
            v = vp;
        }
    }

    u = parent[u];
    return u;
}

void query()
// finding ans. by binary-lifting.
{
    int q;
    cin >> q;
    test(q)
    {
        int u, v;
        cin >> u >> v;
        int ans = lca(u, v); // finding lca.
        cout << ans << "  **\n";
    }
}
void solve()
{
    int n;
    cin >> n;
    getInputs(n);
    dfs(1);
    buildSparceTable();
    query();
}
int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    cin >> t;
    test(t)
        solve();

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

//-------------------------
// 1
// 10
// 2 2 3
// 2 4 5
// 2 6 7
// 0 0
// 2 8 9
// 0 0
// 1 10
// 0
//*******************************
// for (int i = 0; i < childs.size(); i++)
// {
//     cout << i << " -> ";
//     for (int val : childs[i])
//         cout << val << " ";
//     cout << endl;
// }

//?-------------------------------------------------------------------
// int lca(int u, int v)
// {
//     if (level[u] > level[v])
//         swap(u, v);
//     // level[v]>level[u]
//     while (level[u] != level[v])
//         v = parent[v];
//     if (u == v)
//         return u;
//     while (u != v)
//     {
//         u = parent[u];
//         v = parent[v];
//     }
//     return u;
// }

//!===============================================================================
