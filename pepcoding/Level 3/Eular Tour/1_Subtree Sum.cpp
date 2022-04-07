// https://cses.fi/problemset/task/1137/

#include "../header.h"

vector<vi> childs;
int timing = 0;
vi linearTree; // Linear tree
vi depth, startTime, endTime, values;
vi ftree;

void getInputs(int n)
{
    values.resize(n + 1);
    depth.resize(n + 1);
    startTime.resize(n + 1);
    endTime.resize(n + 1);
    childs.resize(n + 1);
    linearTree.resize(2 * n + 5);
    ftree.resize(linearTree.size());
    // building input tree
    for (int i = 1; i <= n; i++)
        cin >> values[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        childs[u].pb(v);
    }
}

void dfs(int node)
{
    startTime[node] = timing;
    linearTree[timing++] = values[node];

    for (int chld : childs[node])
        dfs(chld);

    endTime[node] = timing;
    linearTree[timing++] = values[node];
}
void addFT(int i, int val)
{
    while (i < ftree.size())
    {
        ftree[i] += val;
        i += i & -i;
    }
}
void buildFT()
{
    for (int i = 1; i < timing; i++)
        addFT(i, linearTree[i]);
}
int sumFT(int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += ftree[i];
        i -= i & -i;
    }
    return sum;
}

void query(int q)
{
    test(q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int v, val;
            cin >> v >> val;
            int delta = val - values[v];
            values[v] = val;
            addFT(startTime[v], delta);
            addFT(endTime[v], delta);
        }
        else
        {
            int v;
            cin >> v;
            int sum = sumFT(endTime[v]) - sumFT(startTime[v] - 1);
            sum /= 2;
            cout << sum << "  **\n";
        }
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    getInputs(n);

    // tree flattening
    dfs(1);

    buildFT();

    query(q);
}

int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    // cin >> t;
    test(t)
        solve();
    return 0;
}

// 5 3
// 4 2 5 2 1
// 1 2
// 1 3
// 3 4
// 3 5
// 2 3
// 1 5 3
// 2 3

//! --------------------------------------------------------------------------------------
/*
#include "../header.h"

vector<vi> childs;
int timing = 0;
vi linearTree; // Linear tree
vi depth, startTime, endTime, values;
vi ftree;

void getInputs(int n)
{
    values.resize(n + 1);
    depth.resize(n + 1);
    startTime.resize(n + 1);
    endTime.resize(n + 1);
    childs.resize(n + 1);
    linearTree.resize(n + 5);
    ftree.resize(linearTree.size());
    // building input tree
    for (int i = 1; i <= n; i++)
        cin >> values[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        childs[u].pb(v);
    }
}

void dfs(int node)
{
    startTime[node] = ++timing;

    linearTree[timing] = values[node];
    for (int chld : childs[node])
    {
        depth[chld] = 1 + depth[node];
        dfs(chld);
    }
    endTime[node] = timing;
}
void addFT(int i, int val)
{
    while (i < ftree.size())
    {
        ftree[i] += val;
        i += i & -i;
    }
}
void buildFT()
{
    for (int i = 1; i <= timing; i++)
        addFT(i, linearTree[i]);
}
int sumFT(int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += ftree[i];
        i -= i & -i;
    }
    return sum;
}

void query(int q)
{
    test(q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int v, val;
            cin >> v >> val;
            int delta = val - values[v];
            values[v] = val;
            addFT(startTime[v], delta);
        }
        else
        {
            int v;
            cin >> v;
            int sum = sumFT(endTime[v]) - sumFT(startTime[v] - 1);
            cout << sum << "  **\n";
        }
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    getInputs(n);

    // tree flattening
    dfs(1);

    buildFT();

    query(q);
}
int main()
{
    cout << "\nHello world!" << endl;
    int t = 1;
    // cin >> t;
    test(t)
        solve();
    return 0;
}

// 5 3
// 4 2 5 2 1
// 1 2
// 1 3
// 3 4
// 3 5
// 2 3
// 1 5 3
// 2 3


*/